#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tlv.h"



void tlv_init(tlv_t *tlv){
	memset(&tlv->Tag, 0,sizeof(tlv->Tag));
	memset(&tlv->Len, 0,sizeof(tlv->Len));
	memset(&tlv->Val, 0,sizeof(tlv->Val));
}

void tlvInfo_init(tlvInfo_t *tlv){
	tlv_init(&tlv->tlv);
	memset(&tlv->PC, 0,sizeof(tlv->PC));
	memset(&tlv->Source, 0,sizeof(tlv->Source));
	memset(&tlv->Template, 0,sizeof(tlv->Template));
	tlv->RangeLen=NULL;
	tlv->Description =NULL;
}

tlvInfo_t * tlv_parse(unsigned char *arr, unsigned short size){ 
	/*function to parse tag,len,value and store it in an array, but doesnt parse
	the tags inside value's*/
	unsigned int aux;
	unsigned int index= 0; //tracks arr reading position
	int i,j;
	tlvInfo_t *t;
	tlv_t * tl;
	if(NULL == (t=malloc(sizeof(tlvInfo_t)*size))){
		printf("%s\n", "malloc failed \n");
	}
	if(NULL == (tl = malloc(sizeof(tlv_t)*size))){
		printf("%s\n", "malloc failed \n");	
	}
	for(i=0; i< size;i++){
		t[i].tlv = tl[i];
	}
	
	for(i=0; index < size; i++){
		printf("\n");
		if(arr[index]==0x9F || arr[index]==0x5F)
		{
			t[i].tlv.Tag = arr[index]<<8 | arr[index+1];
			index++;index++;		
		}else
		{
			t[i].tlv.Tag = arr[index];
			index++;
		}
		printf("Tag:%X\n", t[i].tlv.Tag);
		t[i].tlv.Len = arr[index]; index++;
		printf("len:%X\n", t[i].tlv.Len);
		memcpy(t[i].tlv.Val, &arr[index], t[i].tlv.Len);
		printf("val:");
		for(j=0;j <t[i].tlv.Len;j++ ){
			printf("%X", t[i].tlv.Val[j]);
		}
		printf("\n");
		index += t[i].tlv.Len;
	}
	return t;
}

void tlv_subParse(tlvInfo_t * t){//TODO-recursive
	
	unsigned char num=0;//num of parsed tlv's
	int i;
	for(i = 0; t[i].tlv.Tag!=0; i++){
		num++; //will be used as index for save the sub tlv structs
	}
	for (i = 0; t[i].tlv.Tag!=0; i++)
	{
		if(t[i].PC || t[i].Template!=0){ //case where t[i].tlv.Val has a sub tlv struct to parse
			 printf("size:%d",num);
			t[num+i] = *tlv_parse(t[i].tlv.Val, num);
		}
	}
}


