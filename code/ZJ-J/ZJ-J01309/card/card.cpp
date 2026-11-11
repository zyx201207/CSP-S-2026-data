#include <bits/stdc++.h>
using namespace std;
int m,n,a[500005],x = 1,b[500005],c[500005];
bool h[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		x = 1;
		for (int j = i;j <= n;j++)
		{
			for (int k = 1;k <= n;k++)
			{
				if (b[k] == a[j])
				{
					x = k;
					for (int t = k;t <= n;t++)
					{
						b[t] = 0;
					}
					break;
				}
			}
			b[x] = a[j];
			x++;
		}
		for (int j = 1;j <= x;j++)
		{
			c[b[j]]++;
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
