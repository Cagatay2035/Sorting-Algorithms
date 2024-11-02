#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2


struct BTreeNode {
    int items[MAX + 1];
    int count;
    struct BTreeNode *children[MAX + 1];
};


struct BTreeNode *createNode(int item, struct BTreeNode *child) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->items[1] = item;
    newNode->count = 1;
    newNode->children[0] = child;
    newNode->children[1] = NULL;
    return newNode;
}


void insertValue(int item, int pos, struct BTreeNode *node, struct BTreeNode *child) {
    int j = node->count;
    while (j > pos) {
        node->items[j + 1] = node->items[j];
        node->children[j + 1] = node->children[j];
        j--;
    }
    node->items[j + 1] = item;
    node->children[j + 1] = child;
    node->count++;
}


void splitNode(int item, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode) {
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    j = median + 1;
    while (j <= MAX) {
        (*newNode)->items[j - median] = node->items[j];
        (*newNode)->children[j - median] = node->children[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN)
        insertValue(item, pos, node, child);
    else
        insertValue(item, pos - median, *newNode, child);

    *pval = node->items[node->count];
    (*newNode)->children[0] = node->children[node->count];
    node->count--;
}


int setValue(int item, int *pval, struct BTreeNode *node, struct BTreeNode **child) {
    int pos;
    if (node == NULL) {
        *pval = item;
        *child = NULL;
        return 1;
    }

    if (item < node->items[1]) {
        pos = 0;
    } else {
        for (pos = node->count; (item < node->items[pos] && pos > 1); pos--)
            ;
        if (item == node->items[pos]) {
            printf("Duplicate keys not allowed.\n");
            return 0;
        }
    }

    if (setValue(item, pval, node->children[pos], child)) {
        if (node->count < MAX) {
            insertValue(*pval, pos, node, *child);
        } else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}


struct BTreeNode *insert(struct BTreeNode *root, int item) {
    int flag, i;
    struct BTreeNode *child;

    flag = setValue(item, &i, root, &child);
    if (flag)
        root = createNode(i, child);
    return root;
}


int find(struct BTreeNode *root, int item) {
    int pos;
    if (!root)
        return 0;

    if (item < root->items[1]) {
        pos = 0;
    } else {
        for (pos = root->count; (item < root->items[pos] && pos > 1); pos--)
            ;
        if (item == root->items[pos]) {
            return 1;
        }
    }

    return find(root->children[pos], item);
}


int findMin(struct BTreeNode *node) {
    while (node->children[0] != NULL)
        node = node->children[0];
    return node->items[1];
}


void removeValue(struct BTreeNode *node, int pos) {
    for (int i = pos + 1; i <= node->count; i++) {
        node->items[i - 1] = node->items[i];
        node->children[i - 1] = node->children[i];
    }
    node->count--;
}


void borrowFromLeft(struct BTreeNode *node, int pos) {
    struct BTreeNode *leftChild = node->children[pos - 1];
    struct BTreeNode *curChild = node->children[pos];
    
    for (int i = curChild->count; i > 0; i--) {
        curChild->items[i + 1] = curChild->items[i];
        curChild->children[i + 1] = curChild->children[i];
    }
    curChild->children[1] = curChild->children[0];
    curChild->items[1] = node->items[pos];
    curChild->count++;
    
    node->items[pos] = leftChild->items[leftChild->count];
    curChild->children[0] = leftChild->children[leftChild->count];
    leftChild->count--;
}


void borrowFromRight(struct BTreeNode *node, int pos) {
    struct BTreeNode *rightChild = node->children[pos + 1];
    struct BTreeNode *curChild = node->children[pos];
    
    curChild->items[curChild->count + 1] = node->items[pos + 1];
    curChild->count++;
    
    node->items[pos + 1] = rightChild->items[1];
    curChild->children[curChild->count] = rightChild->children[0];
    
    for (int i = 1; i < rightChild->count; i++) {
        rightChild->items[i] = rightChild->items[i + 1];
        rightChild->children[i - 1] = rightChild->children[i];
    }
    rightChild->count--;
}


void mergeNodes(struct BTreeNode *node, int pos) {
    struct BTreeNode *leftChild = node->children[pos - 1];
    struct BTreeNode *curChild = node->children[pos];
    
    leftChild->items[leftChild->count + 1] = node->items[pos];
    for (int i = 1; i <= curChild->count; i++)
        leftChild->items[leftChild->count + 1 + i] = curChild->items[i];
    
    for (int i = 0; i <= curChild->count; i++)
        leftChild->children[leftChild->count + i] = curChild->children[i];
    
    leftChild->count += curChild->count + 1;
    
    for (int i = pos; i < node->count; i++) {
        node->items[i] = node->items[i + 1];
        node->children[i] = node->children[i + 1];
    }
    node->count--;
    free(curChild);
}


void deleteNode(int item, struct BTreeNode *node) {
    int pos, found = 0;
    
    if (node != NULL) {
        if (item < node->items[1]) {
            pos = 0;
        } else {
            for (pos = node->count; (item < node->items[pos] && pos > 1); pos--)
                ;
            if (item == node->items[pos]) {
                found = 1;
            }
        }
        
        if (found) {
            if (node->children[pos - 1]) {
                int pred = findMin(node->children[pos - 1]);
                node->items[pos] = pred;
                deleteNode(pred, node->children[pos - 1]);
            } else {
                removeValue(node, pos);
            }
        } else {
            if (node->children[pos] == NULL) {
                printf("Item not found in tree.\n");
                return;
            }
            
            if (node->children[pos]->count == MIN) {
                if (pos > 0 && node->children[pos - 1]->count > MIN) {
                    borrowFromLeft(node, pos);
                } else if (pos < node->count && node->children[pos + 1]->count > MIN) {
                    borrowFromRight(node, pos);
                } else {
                    if (pos == 0)
                        pos++;
                    mergeNodes(node, pos);
                }
            }
            deleteNode(item, node->children[pos]);
        }
    }
}


void inorder(struct BTreeNode *root) {
    if (root) {
        int i;
        for (i = 0; i < root->count; i++) {
            inorder(root->children[i]);
            printf("%d ", root->items[i + 1]);
        }
        inorder(root->children[i]);
    }
}


int main() {
    struct BTreeNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 7);
    root = insert(root, 17);

    printf("Inorder traversal of the B-tree: ");
    inorder(root);

    int key = 6;
    printf("\nDeleting %d from B-tree.\n", key);
    deleteNode(key, root);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}
