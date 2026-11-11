#include<bits/stdc++.h>
using namespace std;
//bool h1;
int read(int &x)
{
	int O = 0; char c; x = 0;
	for(c = getchar(); (c < '0' || c > '9'); c = getchar()) O |= c == '-';
	for(; ('0' <= c && c <= '9'); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
	x = (O? -x : x);
}
int n, m, a[200002], f[20002][2002], ans;
//bool h2;
bool cmp(int x, int y)
{
	return x < y;
}
bool check(int m)
{
	int op = 1;
	while(op < m)
	{
		if(op & m)
		{
			op <<= 1;
		}
		else return false;
	}
	return true;
}
int main()
{
//	printf("%llfMB\n", (&h2 - &h1)/ 1024.0/1024.0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	read(n); read(m);
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		read(a[i]);
		if(flag && !check(a[i]))
		{
			flag = false;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	if(flag || n > 20000 || m > 2000)
	{
//		cout << 114514 << '\n';
		cout << a[m];
		return 0;
	}
//	f[0][0] = (1 << 30) - 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(j == 1)
			{
				f[i][1] = a[i];
				continue;
			}
			f[i][j] = max(f[i][j], max((f[i - 1][j - 1] & a[i]), f[i - 1][j]));
		}
	}
	cout << f[n][m];
	return 0;
}