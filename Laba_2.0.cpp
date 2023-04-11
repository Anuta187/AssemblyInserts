

#include <iostream>
#include <stdio.h>

int main()
{
	short y, y1, y2, x, a;
	std::cout << "x is "; std::cin >> x;
	std::cout << "a is "; std::cin >> a;
	_asm
	{
		mov ax, x
		mov bx, a

		cmp ax, 1
		jb label1//если меньше
		cmp bx, 0
		ja label5
		neg bx
		add bx, 1
		jmp label5

		label1 :
		cmp ax, 0
			jae label3//если больше
			neg ax
			add ax, 1

			label3 :
			add ax, 8
			jmp label4


			label5 :
		mov ax, a
			mov bx, 2
			mul bl
			jmp label4

			label4 :
		mov y1, ax




			mov ax, x
			mov bx, a
			cmp ax, bx
			je label6
			mov ax, a
			add ax, 1
			jmp label8
			label6 :
		mov ax, 3
			label8 :
			mov y2, ax

	}
	y = y1 % y2;
	printf("%d\n", y1);
	printf("%d\n", y2);
	printf("%d\n", y);
	return 0;
}

