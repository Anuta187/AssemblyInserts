#include <stdio.h>
int main()
{
	short A,B;
	;
	_asm {

		mov ax, 12
		mov bx, 5
		div bl
		mov ah, 0
		mov A, ax

		push ax
		mov ax, 15
		mov bx, 9
		div bl
		mov ah, 0
		mov B, ax

		mov bx, ax
		pop ax
		add ax, bx

		push ax

		mov ax, 8
		add ax, 6
		mov bx, ax
		pop ax
		div bl
		mov ah, 0

		push ax//0

		mov ax, 13
		mov bx, 3
		div bl
		mov ah, 0

		push ax//4 0

		mov ax, 2
		mov bx, 4
		div bl
		mov ah, 0

		mov bx, ax
		pop ax//0
		sub ax, bx

		push ax// 4 0

		mov ax, 3
		sub ax, 2
		mov bx, ax
		pop ax
		div bl
		mov ah, 0

		mov bx, ax
		pop ax
		add ax, bx
		mov B, ax

	}
	printf("%d", B);
}