#ifndef TLV_H
#define TLV_H


typedef struct tlv{
	unsigned short tag;
	unsigned char *description;
	unsigned short len;
	unsigned long val;
}tlv_t;

void tlv_init(tlv_t *tlv);
void tlv_decode(unsigned char arr[], tlv_t *tlv);
void tlv_printHEXtag(tlv_t *tlv);

#endif