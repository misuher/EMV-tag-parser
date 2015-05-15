#include "emvTagList.h"
#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

tlvInfo_t * tlvInfo_set(unsigned char PC,unsigned char Source,
	unsigned short Template, unsigned char *RangeLen, unsigned char *Description){

	tlvInfo_t *t= malloc(sizeof(tlvInfo_t));
	tlvInfo_init(t);
	t->PC = PC;
	t->Source = Source;
	t->Template=Template;
	t->RangeLen = RangeLen;
	t->Description = Description;
	return t;
}

tlvInfo_t * tlvInfo_get(unsigned short Tag,dict_t *hashtab[HASHSIZE]){

}

void emvInit(dict_t *hashtab[HASHSIZE])
{
	addItem(0x9F01,tlvInfo_set(0,0,0x22," ","ggffkgkjh "), hashtab);
	/*addItem("9F40", "Additional Terminal Capabilities", hashtab);
	addItem("81", "Amount, Authorised(Binary)", hashtab);
	addItem("9F02", "Amount, Authorised(Numeric)", hashtab);
	addItem("9F04", "Amount, Other(Binary)", hashtab);
	addItem("9F03", "Amount, Other(Numeric)", hashtab);
	addItem("9F3A", "Amount, Reference Currency", hashtab);
	addItem("9F26", "Application Cryptogram", hashtab);
	addItem("9F42", "", hashtab);/*
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("", "", hashtab);
	addItem("6F", "File Control Information(FCI) Template", hashtab);
	addItem("9F4C", "ICC Dynamic Number", hashtab);
	*/
}