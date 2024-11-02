#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 256 

/* La fonction de hachage dont le pseudocode est
 * donne sur l'enonce de TP */
unsigned long hash_compute(const char *str){
	unsigned long h = 0;
	while(*str){
		h = (h * MULTIPLIER + *str) % MAXBUCKETS;
		*str++;
	
	}
	return h;
}

/* La table represente la structure de hach.
 * Si la chaine de caractere existe deja dans la liste
 * alors on retourne son adresse, sinon et si create == 1
 * alors on ajoute cette chaine à la table de hachage */
Key* hash_lookup(Key **table, const char *str, int create){
	unsigned long h = hash_compute(str);
	Key *list = table[h];
	while (list != NULL) {
		if (strcmp(list->word, str) == 0){
			return list;
		}
		list = list->next;
	}
	if (create) {
		Key *new_key = malloc(sizeof(Key));
		if (new_key == NULL) {
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		new_key->word = strdup(str);
		new_key->count = 0;
		new_key->next = table[h];
		table[h] = new_key;
		return new_key;
	}
	return NULL;
}

/* Une fonction pour effacer la table entiere.
 * Vous devez liberer (free) chaque noeud et chaque 
 * word qui se toruvent dans la liste chainee. */
void hash_free(Key **table){
	for (int i = 0; i < MAXBUCKETS; i++) {
		Key *current = table[i];
		while (current != NULL) {
			Key *next = current->next;
			free(current->word);
			free(current);
			current = next;
		}
	}
}

/* Une fonction pour afficher les mots dont 
 * la frequence >= n. Pour l'affichage utiliser
 * le format "%30s-->%5ld\n" 
 * (ld pour unsigned long) */
void hash_dump(Key **table,int n){
	for (int i = 0; i < MAXBUCKETS; i++) {
		Key *current = table[i];
		while (current != NULL) {
			if (current->count >= n)
				printf("%30s --> %5ld\n", current->word, current->count);
			current = current->next;
		}
	}
}