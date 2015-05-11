#define "hashtable.h"

dict_t *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->key) == 0)
          return np; /* found */
    return NULL; /* not found */
}

dict_t *addItem(char *key, char *value)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(key)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->key = strdup(key)) == NULL)
          return NULL;
        hashval = hash(key);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->value); /*free previous value */
    if ((np->value = strdup(value)) == NULL)
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

char *strdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}