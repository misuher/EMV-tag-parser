#include <stdio.h>
#include <string.h>
#include "tlv.h"

void tlv_init(tlv_t *tlv){
	memset(&tlv->Tag, 0,sizeof(tlv->Tag));
	memset(&tlv->Len, 0,sizeof(tlv->Len));
	tlv->Val=NULL;
}

void tlvInfo_init(tlvInfo_t *tlv){
	memset(&tlv->PC, 0,sizeof(tlv->PC));
	memset(&tlv->Source, 0,sizeof(tlv->Source));
	memset(&tlv->Template, 0,sizeof(tlv->Template));
	tlv->RangeLen=NULL;
	tlv->Description =NULL;
}

void tlv_decode(unsigned char arr[], tlv_t *tlv){ /* TODO: in process */
	
	if(arr[0]==0x9F || arr[0]==0x5F)
	{
		unsigned short aux;
		aux = arr[0]<<8 | arr[1];
		memcpy(&tlv->Tag, &aux, 2);
	}else
	{
		memcpy(&tlv->Tag, arr, 1);
	}
}

void tlv_printHEXtag(tlv_t *tlv){
	printf("\n %X", tlv->Tag);
}