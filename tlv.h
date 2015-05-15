#ifndef TLV_H
#define TLV_H

#define SIZE 200

typedef struct{
	unsigned short Tag;
	unsigned short Len;
	unsigned char Val[SIZE];  
}tlv_t;

typedef struct{
	tlv_t tlv;
	unsigned char PC; /* primitive || constructed */
	unsigned char Source; /* ICC || Terminal */
	unsigned short Template;
	unsigned char *RangeLen; /* rango teorico de la longitud del campo */
	unsigned char *Description;
}tlvInfo_t;

void tlv_init(tlv_t *tlv);
void tlvInfo_init(tlvInfo_t * tlv);
tlvInfo_t * tlv_parse(unsigned char arr[], unsigned short size);
void tlv_getTagData(tlvInfo_t * t);



#endif