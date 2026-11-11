#include <bits/stdc++.h>
using namespace std;

int g[200010], s[200010], c[100010], k[100010];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, l;
	cin >> n >> m;
	if (n > 200000)
	{
		cout << rand();
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> g[i];
	}
	for (int i = 1;i <= n;i++)
	{
		l = 1;
		memset(s, 0, sizeof(s));
		memset(c, 0, sizeof(c));
		for (int j = i;j <= n;j++)
		{
			if (c[g[j]] == 0)
			{
				s[l] = g[j];
				c[g[j]] = l;
				l += 1;
			}
			else
			{
				for (int w = c[g[j]] + 1;w < l;w++)
				{
					c[s[w]] = 0;
					s[w] = 0;
				}
				l = c[g[j]] + 1;
			}
		}
		for (int i = 1;i <= m;i++)
		{
			if (c[i] != 0) k[i] += 1;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << k[i] << " ";
	}
	return 0;
}
