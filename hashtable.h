#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHSIZE 200

typedef struct nlist{ 
    struct nlist *next; 
    char *key; 
    char *value; 
}dict_t;

dict_t *lookup(char *s, dict_t *hashtab[HASHSIZE]);  //buscar en el dict
dict_t *addItem(char *name, char *defn, dict_t *hashtab[HASHSIZE]);
unsigned hash(char *s);
char *strdupp(char *s);
void displayTable(dict_t *hashtab[HASHSIZE]);


#endif //HASHTABLE_H