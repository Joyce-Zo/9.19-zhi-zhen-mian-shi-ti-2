#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

二维数组
int main()
{
	int a[3][4] = { 0 };

	printf("%d\n", sizeof(a));			// 48 整个数组大小，4*3*4=48
	printf("%d\n", sizeof(a[0][0]));	// 4  第一行第一列第一个元素的大小，int=4
	printf("%d\n", sizeof(a[0]));		// 16 a[0]相当于第一行作为一维数组的数组名
			sizeof(a[0]) - 数组名放进去，整个数组大小 - 整个一维数组大小，4*4=16
	printf("%d\n", sizeof(a[0] + 1));	// 8/4 a[0]+1不是数组名放入，
		  a[0]是首元素地址，代表第一行第一个元素的地址，+1代表第一行第二个元素的地址，地址4/8
	printf("%d\n", sizeof(*(a[0] + 1))); // 4 解引用，表示第一行第二个元素的大小
	printf("%d\n", sizeof(a + 1));		// 8/4 a不是数组名也不是&数组名，所以a是首元素地址，
		  a作为一维数组的地址，+1代表二维数组第二个元素(第二行)的地址，地址4/8
	printf("%d\n", sizeof(*(a + 1)));	// 16 第二行数组的大小
	printf("%d\n", sizeof(&a[0] + 1));	// 8/4 第二行的地址，地址4/8
	printf("%d\n", sizeof(*(&a[0] + 1))); // 16 第二行整个数组的大小
	printf("%d\n", sizeof(*a));			// 16 a首元素地址，*a就是整个第一行的元素
	printf("%d\n", sizeof(a[3]));		// 16 sizeof()并不真正访问，而是计算某类型的大小

	return 0;
}

int main()
{
	int a[5] = { 1, 2,	3,	4, 5 };
	int* ptr = (int*)(&a + 1);	// 
					 &a整个数组的地址，+1跨越数组后，到下一个地方的地址，存在ptr里
	printf("%d,%d ", *(a + 1), *(ptr - 1)); 
		 a首元素1的地址，+1则是 2//ptr-1是5，
	return 0;
}

struct Test 
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
假设p的值为0x100000。如下表表达式的值分别为多少?
结构体p类型的变量大小是20字节
 p 1000000000 0000000000
int main()
{
	p =(struct Test*)0x100000;
	printf("%p\n", p + 0x1);	// 结构体指针+1 - 跨越一个结构体20字节，
			 0x100014 - 14(16进制) ->20字节
	printf("%p\n", (unsigned long)p + 0x1);//  100000 ->10进制1048576，+1=1048577,转化为16进制，100001
				100000+1 - 100001
	printf("%p\n", (unsigned int*)p + 0x1);//
			   100000+int*(4) - 100004
	return 0;
}
