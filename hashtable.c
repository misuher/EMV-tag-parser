#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

dict_t *lookup(char *s, dict_t *hashtab)
{
    dict_t *np;
    for (np = &hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->key) == 0)
          return np; /* found */
    return NULL; /* not found */
}

dict_t *addItem(char *key, char *value, dict_t *hashtab)
{
    dict_t *np;
    unsigned hashval;
    if ((np = lookup(key, hashtab)) == NULL) { /* not found */
        np = (dict_t *) malloc(sizeof(*np));
        if (np == NULL || (np->key = strdupp(key)) == NULL)
          return NULL;
        hashval = hash(key);
        np->next = &hashtab[hashval];
        hashtab[hashval] = *np;
    } else /* already there */
        free((void *) np->value); /*free previous value */
    if ((np->value = strdupp(value)) == NULL)
       return NULL;
    return np;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

char *strdupp(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}
