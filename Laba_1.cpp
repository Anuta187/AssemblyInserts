#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	short A, B;
	_asm
	{
		mov ax, 00000101b
		shl ax, 4//01010000
		mov B, ax;
		and ax, 00000001b //( ax = 00000000)
			shl ax, 7 // (000000000)
			mov A, ax
			mov ax, B
			and ax, 10000000b // (ax=00000000)
			shr ax, 7 //(00000000)
			or ax, A //(00000000)
			and B, 01111110b // (01010000)
			or B, ax//(01010000)

			mov ax, B//(01010000)
			and ax, 01000000b // 01000000
			shr ax, 5//00000010
			mov A, ax//00000010
			mov ax, B // 01010000
			and ax, 00000010b // 00000000 
			shl ax, 5 // 00000000
			or ax, A // 000000010
			and B, 10111101b // 00010000
			or B, ax // 00010010

			mov ax, B//00010010
			and ax, 00100000b // 00000000
			shr ax, 3//00000000
			mov A, ax//00000000
			mov ax, B //00010010

			and ax, 00000100b // 00000000 
			shl ax, 3 // 00000000
			or ax, A // 00000000
			and B, 11011011b //00010010
			or B, ax //00010010

			mov ax, B//00010010
			and ax, 00010000b // 00010000
			shr ax, 1//00001000
			mov A, ax//00001000
			mov ax, B //00010010
			and ax, 00001000b // 00000000 
			shl ax, 1 // 00000000
			or ax, A // 00001000
			and B, 11100111b //00010000
			or B, ax // 00001010

	}
	printf("%d", B);
}
