#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// La structure de noeud
struct node {
	int data;
	struct node *left;
	struct node *right;
};

// Pour creer un nouveau noeud
struct node* newNode(int data) {
	struct node* new = malloc(sizeof(struct node));
	assert(new);
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// Calcul de la hauteur de l'arbre (recursive)
int findHeight(struct node *root) {
	if (root == NULL)
		return -1;
	int h_left = findHeight(root->left);
	int h_right = findHeight(root->right);
	if (h_left > h_right)
		return 1 + h_left;
	else
		return 1 + h_right;
}

/***** Parcours des Arbres *****/

// Parcours infixe recursive
void printTreeInOrder(struct node* root) {
	if (root != NULL) {
		printTreeInOrder(root->left);
		printf("%d ", root->data);
		printTreeInOrder(root->right);
	}
}

// Parcours prefixe recursive
void printTreePreOrder(struct node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

// Parcours postfixe recursive
void printTreePostOrder(struct node* root) {
	if (root != NULL) {
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d ", root->data);
	}
}

// Affichage des noeuds sur le meme niveau (recursive)
void printLevel(struct node *root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1) {
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

// Parcours par niveau
void printTreeLevelOrder(struct node* root) {
	int h = findHeight(root);
	for (int i = 0; i <= h; i++)
		printLevel(root, i + 1);
}

/***** Operations sur les ABR *****/

// Recherche recursive d'un element dans un ABR
struct node* findRec(struct node* root, int key) {
	if (root == NULL || root->data == key)
		return root;
	if (key < root->data)
		return findRec(root->left, key);
	return findRec(root->right, key);
}

// Recherche iterative d'un element dans un ABR
struct node* findIter(struct node* root, int key) {
	while (root != NULL) {
		if (key == root->data)
			return root;
		if (key < root->data)
			root = root->left;
		else
			root = root->right;
	}
	return NULL;
}

// Minimum dans un ABR
struct node* findMini(struct node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

// Maximum dans un ABR
struct node* findMaxi(struct node* root) {
	while (root->right != NULL)
		root = root->right;
	return root;
}

// Insertion d'un nouvel element d'ABR
struct node* insert(struct node* root, int key) {
	if (root == NULL)
		return newNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);
	return root;
}

// Suppression d'un element d'ABR
struct node* delete(struct node* root, int key) {
	if (root == NULL)
		return root;
	if (key < root->data)
		root->left = delete(root->left, key);
	else if (key > root->data)
		root->right = delete(root->right, key);
	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = findMaxi(root->left);
		root->data = temp->data;
		root->left = delete(root->left, temp->data);
	}
	return root;
}

int main(void) {
	struct node* r = newNode(23);
	r->left = newNode(18);
	r->right = newNode(44);
	r->left->left = newNode(12);
	r->left->right = newNode(20);
	r->right->left = newNode(35);
	r->right->right = newNode(52);
	r->right->right->left = newNode(47);
	r->right->right->right = newNode(53);
	
	// Affichez la hauteur de l'arbre
	printf("Hauteur    : %d", findHeight(r));
	
	// Parcours de l'arbre en utilisant le parcours
	// prefixe, infixe, postfixe et par niveau
	printf("\nPrefixe    : ");
	printTreePreOrder(r);
	printf("\nInfixe     : ");
	printTreeInOrder(r);
	printf("\nPostfixe   : ");
	printTreePostOrder(r);
	printf("\nPar Niveau : ");
	printTreeLevelOrder(r);
	
	printf("\n\n--- Recherche ---\n");
	
	// Recherche recursive de 37
	struct node* searchResult = findRec(r, 37);
	if (searchResult != NULL)
		printf("Trouve (rec): %d\n", searchResult->data);
	else
		printf("37 non trouve (rec)\n");
	
	// Recherche iterative de 53
	searchResult = findIter(r, 53);
	if (searchResult != NULL)
		printf("Trouve (iter): %d\n", searchResult->data);
	else
		printf("53 non trouve (iter)\n");
	
	// Affichage des cles min et max
	struct node* min = findMini(r);
	struct node* max = findMaxi(r);
	printf("Min: %d, Max: %d\n", min->data, max->data);
	
	printf("\n--- Insertion ---\n");
	
	// Insertion d'un element dont la cle est 19
	r = insert(r, 19);
	printf("Apres insertion de 19 : ");
	printTreeInOrder(r);
	
	// Construisez un ABR en prenant les cles des 
	// noeuds de la console comme arguments 
	// Pour copy-paste : 23 11 29 5 17 41 7 13 19 37 53
	int keys[] = {23, 11, 29, 5, 17, 41, 7, 13, 19, 37, 53};
	struct node* newTree = NULL;
	for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
		newTree = insert(newTree, keys[i]);
	}
	
	printf("\nNouvel ABR : ");
	printTreeInOrder(newTree);
	
	printf("\n\n--- Suppression ---\n");
	
	// On va supprimer 37, 29 et 11
	newTree = delete(newTree, 37);
	newTree = delete(newTree, 29);
	newTree = delete(newTree, 11);
	
	// Affichage du nouveau ABR
	printf("Apres suppression de 37, 29, 11 : ");
	printTreeInOrder(newTree);
	
	return 0;
}
