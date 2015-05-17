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
}

void emvPrint_result(tlvInfo_t* t, int tindex){
	int i,j;
	int tabs=1;
	int composedLen, trackLen ;
	printf("\n" );
	for(i=0; i<tindex; i++){
		if(trackLen >=composedLen) tabs--;
		printf("%sTag:%X(%s)\n", emvPrint_tabs(tabs), t[i].tlv.Tag, t[i].Description);
		printf("%slen:%X(decimal: %d )\n", emvPrint_tabs(tabs+1), t[i].tlv.Len, t[i].tlv.Len);
		printf("%sTemplate:%X\n", emvPrint_tabs(tabs+1), t[i].Template);
		printf("%sSource:%s\n", emvPrint_tabs(tabs+1), t[i].Source?"ICC" : "Terminal");
		printf("%sType:%s\n", emvPrint_tabs(tabs+1), t[i].PC?"Constructed" : "Primitive");
		printf("%sType:%s\n", emvPrint_tabs(tabs+1), t[i].RangeLen ? t[i].RangeLen : "Unknown");
		if(t[i].PC == COMPOSED){
			trackLen =0;
			composedLen = t[i].tlv.Len;
			tabs++;
		}else{
			printf("%s%s",emvPrint_tabs(tabs+1), "val:");
			for(j=0; j< t[i].tlv.Len; j++){
				printf("%X", t[i].tlv.Val[j]);
			}
			printf("\n");
			trackLen += sizeof(t[i].tlv.Tag);
			trackLen += sizeof(t[i].tlv.Len);
			trackLen += t[i].tlv.Len;
		}
	}
}

char * emvPrint_tabs(int numTabs){
	switch (numTabs) {
		case 0: return ""; break;
		case 1: return "\t"; break;
		case 2: return "\t\t"; break;
		case 3: return "\t\t\t"; break;
		case 4: return "\t\t\t\t"; break;
		case 5: return "\t\t\t\t\t"; break;
		case 6: return "\t\t\t\t\t\t"; break;
		case 7: return "\t\t\t\t\t\t\t"; break;
		case 8: return "\t\t\t\t\t\t\t\t"; break;
		case 9: return "\t\t\t\t\t\t\t\t\t"; break;
		default: return "\t\t\t\t\t\t\t\t\t"; break;
	}
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
