#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct nlist{ 
    struct nlist *next; 
    char *key; 
    char *value; 
}dict_t;

dict_t *lookup(char *s)  //buscar en el dict
dict_t *addItem(char *name, char *defn);
unsigned hash(char *s);
char *strdup(char *s);

#endif //HASHTABLE_H