#include <bits/stdc++.h>
using namespace std;
int ax, ay, bx, by;
char a, b;

bool check(char a, char b)
{
	if (a == 'A' && b == 'B') return 1;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'D' && b == 'F') return 1;
	return 0;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d %d%c %d %d%c", &ax, &ay, &a, &bx, &by, &b);
	if (ax == bx)
	{
		printf("1");
		if (ay == by)
		{
			printf("1");
			int af, bf;
			if (a == 'A' || a == 'B' || a == 'C') af = 1;
			else af = 2;
			if (b == 'A' || b == 'B' || b == 'C') bf = 1;
			else bf = 2;
			if (af == bf)
			{
				printf("1");
				if (check(a, b)) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}