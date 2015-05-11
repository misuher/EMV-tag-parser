#ifndef TLV_H
#define TLV_H


typedef struct tlv{
	unsigned short tag;
	unsigned short len;
	unsigned long val;  
}tlv_t;

typedef struct additionData{
	tlv_t tlv;
	unsigned char PC; /* primitive || constructed */
	unsigned char source; /* ICC || Terminal */
	unsigned char Template;
	unsigned char rangeLen; /* rango teorico de la longitud del campo */
	unsigned char *description;
}atlv_t;

void tlv_init(tlv_t *tlv);
void tlv_decode(unsigned char arr[], tlv_t *tlv);
void tlv_printHEXtag(tlv_t *tlv);

#endif