#ifndef TLV_H
#define TLV_H


typedef struct{
	unsigned short Tag;
	unsigned short Len;
	unsigned char *Val;  
}tlv_t;

typedef struct{
	tlv_t *tlv;
	unsigned char PC; /* primitive || constructed */
	unsigned char Source; /* ICC || Terminal */
	unsigned short Template;
	unsigned char *RangeLen; /* rango teorico de la longitud del campo */
	unsigned char *Description;
}tlvInfo_t;

void tlv_init(tlv_t *tlv);
void tlvInfo_init(tlvInfo_t * tlv);
void tlv_decode(unsigned char arr[], tlv_t *tlv);
void tlv_printHEXtag(tlv_t *tlv);

#endif