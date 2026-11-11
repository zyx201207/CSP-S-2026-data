#include <cstdio>

int c1, s1, c2, s2;
char ch1, ch2;

int main(void)
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%d %d%c %d %d%c", &c1, &s1, &ch1, &c2, &s2, &ch2);
	
	if (c1 == c2) putchar('1');
	else putchar('0');
	
	if (c1 == c2 && s1 == s2) putchar('1');
	else putchar('0');
	
	if (c1 == c2 && s1 == s2 && (('A' <= ch1 && ch1 <= 'C' && 'A' <= ch2 && ch2 <= 'C') || ('D' <= ch1 && ch1 <= 'F' && 'D' <= ch2 && ch2 <= 'F'))) putchar('1');
	else putchar('0');
	
	if (c1 == c2 && s1 == s2 && (('A' <= ch1 && ch1 <= 'C' && 'A' <= ch2 && ch2 <= 'C') || ('D' <= ch1 && ch1 <= 'F' && 'D' <= ch2 && ch2 <= 'F')) && (ch1 == ch2 + 1 || ch2 == ch1 + 1)) putchar('1');
	else putchar('0');

	#define _ 0
	return ~~(0^_^0);
	#undef _	
}

