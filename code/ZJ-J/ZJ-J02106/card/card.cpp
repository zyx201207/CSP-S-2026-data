#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long ans = 0, n, m, a[10000], b[10000], c[10000];
	int x = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		c[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		long long l = 1;
		b[1] = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			int u = l;
			for (int k = 1; k <= l; k++)
			{
				if (b[k] == a[j])
				{
					for (int t = k + 1; t <= l; t++)
					{
						b[t] = 0;
					}
					l = k;
					x = 1;
					break;
				}
			}
			if (x == 0)
			{
				b[l + 1] = a[j];
			    l++;
			}
			x = 0;
		}
		for (int j = 1; j <= l; j++)
		{
			c[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}