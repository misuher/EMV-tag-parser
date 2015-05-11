#include "emvTagList.h"
#include "hashtable.h"

void emvInit(dict_t *hashtab[HASHSIZE])
{
	addItem("6F", "File Control Information(FCI) Template", hashtab);
	addItem("9F4C", "ICC Dynamic Number", hashtab);
}