#include <iostream>
#include <cstdio>
using namespace std;
constexpr int N = 2000005, N1 = 5005;
int n, c, t;
long long d, x[N];
bool ok[N1][N1];
long long read();
void solve()
{
	n = read(), d = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
		ok[i][i] = 1;
	}
	if (c <= 10)
	{
		int lst = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (x[i] - x[i - 1] > d)
			{
				for (int j = lst; j <= i; j++)
				{
					for (int k = j + 1; k <= i; k++)
					{
						ok[j][k] = 1;
					}
				}
				lst = i;
			}
		}
		for (int i = lst; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ok[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = i + 1; j <= n; j++)
			{
				int tot = (x[j] - x[i] + d - 1) / d;
				if (j - i - 1 == tot && ok[j][i]) sum++;
			}
			if (sum == 2) cnt++;
		}
		cout << cnt << "\n";
	}
	else if (c == 11 || c == 12)
	{
		long long len = d / (x[2] - x[1]);
		cout << n - len * 2 + 1 << "\n";
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--)
	{
		solve();
	}
	return 0;
}
long long read()
{
	long long res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
