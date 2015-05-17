#include "emvTagList.h"
#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

#define COMPOSED 1
#define PRIMITIVE 0

tlvInfo_t * emvInfo_set(unsigned char PC,unsigned char Source,
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

int emvInfo_get(tlvInfo_t *t,int * tindex, dict_t *hashtab[HASHSIZE]){

	dict_t * dict;

	dict = lookup(&t[*tindex].tlv.Tag, hashtab);
	if(dict == NULL){
		printf("%s\n","Tag not in list" );
		return 1;
	}
	t[*tindex].PC = dict->value->PC;
	t[*tindex].Source = dict->value->Source;
	t[*tindex].Template = dict->value->Template;
	t[*tindex].RangeLen = dict->value->RangeLen;
	t[*tindex].Description = dict->value->Description;
	printf("PCinget:%d\n", t->PC);
	return 0;
}

tlvInfo_t emvparse(unsigned char arr[], unsigned short size, tlvInfo_t * t, int * tindex, int index, dict_t *hashtab[HASHSIZE]){
	/* 	arr: Value
		size: numero de elementos de arr
		t: array de tlvInfo_t para ir guardando los resultados
		tindex:index en el que guardar cada tlv dentro de t
		index: index para saber la reading position de los campos Value de tlv
		hashtab: diccionario para consultar los datos de los tags previamente almacenados
		*/
		t[*tindex].tlv =  *tlv_parse(arr, &index);
		if(1==emvInfo_get(t, tindex, hashtab)){
			//Tag desconocido, no lo guardamos ximplemente por no actualizar *tindex
			printf("Tag desconocido: %X\n", t[*tindex].tlv.Tag);
		}
		*tindex +=1;

		if(t[*tindex-1].PC == COMPOSED){
		 	emvparse(t[*tindex-1].tlv.Val, \
				t[*tindex-1].tlv.Len, t, tindex, 0 , hashtab);
		}
		if(index >= size){
			return;
		}
		{ //several consecutive primite tlv's
			return emvparse(&arr[index], size-index , t, tindex, 0 , hashtab);
		}
	printf("%s\n", "NO RETURN");
}

void emvPrint_result(tlvInfo_t* t){

}

void emvInit(dict_t *hashtab[HASHSIZE])
{
	addItem(0x9F01,emvInfo_set(PRIMITIVE,0,0x22," ","ggffkgkjh "), hashtab);
	addItem(0x6F, emvInfo_set(COMPOSED,0,0x22," ","ggffkgkjh "), hashtab);
	/*addItem("81", "Amount, Authorised(Binary)", hashtab);
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
