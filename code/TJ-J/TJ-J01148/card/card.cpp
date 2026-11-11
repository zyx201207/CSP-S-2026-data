#include <bits/stdc++.h>
using namespace std;
int a[500005][500005],ans[300005],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++)
	{
		for(int j = i-1;j <= n; j++)
		{
			int x;
			cin >> x;
			a[i][j] = x;
			for(int k = 1;k <= n;k++)
			{
				if(a[i][k] == x)
				{
					for(int l = k;l <= n;l++)
						a[i][l] = 0;
					a[i][j] = x;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= m;k++)
			{
				if(a[i][j] == k)
					ans[k]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}
