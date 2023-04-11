#include <stdio.h>
int main()
{
	short int a, x;
	x = -2;
	_asm {
		mov ax, x
		//x >= 0
		cmp ax, 0
		jl A1
		mov cx, x
		mov ax, x
		mov bx, 8
		mul cx
		mul bx
		jmp A

		//x < 0
		A1 :
		mov ax, x
			neg ax
			mov bl, 2
			div bl
			mov ah, 0
			jmp A

			A :
		mov a, ax
	}
	printf("%d", a);
}