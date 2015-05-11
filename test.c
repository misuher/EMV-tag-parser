
#include <stdio.h>
#include <string.h>
#include "tlv.h"
#include "hashtable.h"


int main(){
	/*Se hace un test con la cadena hexadecimal 6F1A840E315041592E5359532E4444463031A5088801025F2D02656E
	cuyo significado es el siguiente:
	6F(File Control Information(FCI) Template)
		1A
		84(Dedicated File(DF) Name)
			0E -len
			315041592E5359532E4444463031 - value(1PAY.SYS.DDF01 en hexa)
		A5(File Control information(FCI) Propietary template)
		08-len
			88(Short File Identifier(SFI))
				01- len
				02 -value
			5F2D(language preference)
				02-len
				656E-value
	*/
	dict_t *dict[HASHSIZE]; 
	unsigned char test[] = {0x6F,0x1A,0x84,0x0E,0x31,0x50,0x41,0x59,0x2E,0x53,0x59,0x53,0x2E,0x44,0x44,0x46,0x30,0x31,0xA5,0x08,0x88,0x01,0x02,0x5F,0x2D,0x02,0x65,0x6E};
	tlv_t t;
	tlv_init(&t);
	tlv_decode(test, &t);
	tlv_print(&t);
	return 0;
}