#ifndef EMVTAGLIST_H
#define EMVTAGLIST_H

#include "hashtable.h"
#include "tlv.h"


tlvInfo_t * tlvInfo_set(unsigned char PC,unsigned char Source,
	unsigned short Template, unsigned char *RangeLen, unsigned char *Description);

void tlvInfo_get(tlvInfo_t * t,dict_t *hashtab[HASHSIZE]);

void emvInit(dict_t *hashtab[HASHSIZE]);

#endif //EMVTAGLIST_H