#include<bits/stdc++.h>
using namespace std;

int n;
inline int read()
{
	int x = 0, c = getchar(), k = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); 
	if (c == '-') k = -1, c = getchar();
	do x = x * 10 + (c ^ 48), c = getchar();
	while('0' <= c && c <= '9');
	return x * k;
}
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	return 0;
}

