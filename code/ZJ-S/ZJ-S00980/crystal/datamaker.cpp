#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m;

int main()
{
	freopen("crystal.in", "w", stdout);
	n = 5e5, m = 6;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", i * 2 - 1);
	}
}
/*
5 5 1 7 7 8 9
*/
