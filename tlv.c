#include "tlv.h"
#include <stdio.h>
#include <string.h>


void tlv_init(tlv_t *tlv){
	memset(&tlv->tag, 0,sizeof(tlv->tag));
	memset(&tlv->len, 0,sizeof(tlv->len));
	memset(&tlv->val, 0,sizeof(tlv->val));
}

void tlv_decode(unsigned char arr[], tlv_t *tlv){
	
	if(arr[0]==0x9F || arr[0]==0x5F)
	{
		unsigned short aux;
		aux = arr[0]<<8 | arr[1];
		memcpy(&tlv->tag, &aux, 2);
	}else
	{
		memcpy(&tlv->tag, arr, 1);
	}
}

void tlv_print(tlv_t *tlv){
	printf("\n %X", tlv->tag);
}