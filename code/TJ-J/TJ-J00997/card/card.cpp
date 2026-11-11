#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], p, d[1000005];
int b[1000005], c[1000005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out","w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if (b[a[j]] > 0)
			{
				int sum = 0;
				for (int x = b[a[j]] + 1;x <= p;x++)
				{
					b[d[x]] = 0;
					d[x] = 0;
					sum++;
				}
				p -= sum;
			}
			else
			{
				d[++p] = a[j];
				b[a[j]] = p;
			}
		}
		for (int j = 1;j <= m;j++)
		{
			if (b[j] > 0)
			{
				c[j]++;
			}
		}
		for (int j = 1;j <= n;j++)
		{
			b[j] = 0;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
