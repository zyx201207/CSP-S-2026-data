#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n;
	cin >> m;
	int a[1000005];
	int d[1005][1005];
	int maxn = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		sort(a+1,a+n+1);
		cout << a[n];
	}
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1; j <= n;j++)
			{
				d[i][j] = a[i] & a[j];
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (d[i][j] > maxn)
				{
					maxn = d[i][j];
				}
			}
		}
		cout << maxn;
	}
	return 0; 
}
