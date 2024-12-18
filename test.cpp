#include <stdlib.h>
#define _RM(float)RAND_MAX
#define _R(float)rand()
#define pc putchar
#define td typedef
#define pf printf
td char _C;
td int _I;
td void _V;
//_C s()
//{
//	return ((rand() / _RM(float) > 0.95) ? '.' : ' ');
//}
//_V t(_I p, _I z, _I o = 0, _C c)
//{
//	for (_I i = 1; i < z; i++, pc('\n'))
//		for (_I j = 0; i < p * 2; j++, pc((j <= (p - i - o) || j >= (p + i + o)) ? s() : '#'));
//}
//
//_V r(_I p, _I w, _I h)
//{
//	for (_I j = 0; j < p * 2; j++, pc((j <= (p - w) || j >= (p + w)) ? ' ' : '#'));
//}
//
//_I main()
//{
//	t(16, 4), t(16, 5, 1), t(16, 6, 2), t(16, 2, 3);
//	pf("\n - MERRY CHRISTMAS FROM BEN - \n");
//}

#include <iostream>


char snow()
{
	if ((rand() / (float)RAND_MAX) > 0.95)
		return '.';
	else
		return ' ';
}

void Triangle(int cpos, int size, int offset = 0, char c = '#')
{
	for (int i = 1; i < size; i++, putchar('\n'))
	{
		for (int j = 0; j < cpos * 2; j++)
		{
			if (j <= (cpos - i - offset) || j >= (cpos + i + offset))
				putchar(snow());
			else
				putchar('#');
		}
	}
}

void Rect(int cpos, int w, int h)
{
	for (int line = 0; line < h; line++, putchar('\n'))
	{
		for (int j = 0; j < cpos * 2; j++)
		{
			if (j <= (cpos - w) || j >= (cpos + w))
				putchar(' ');
			else
				putchar('#');
		}
	}
}

int main(int argc, char* argv[])
{
	Triangle(16, 4);
	Triangle(16, 5, 1);
	Triangle(16, 6, 2);
	Rect(16, 2, 3);
	printf("\n -  MERRY CHRISTMAS FROM BEN - \n");
}
