#include <bits/stdc++.h>
using namespace std;
long long n, m,cnt = 0,q = 5000005,ans = 0;
int a[200005],g[200005],f[200005],vis[2][200005];
int main();
{
	freopen ("")
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int x = n-m-1;
	do
	{
		f[1] = a[1];
		for (int i = 2;i <= n;i++)
		{
			f[i] ^= f[i-1];
		}
		g[n] = a[n];
		for (int i = n-1;i <= 1;i++)
		{
			g[i] ^= g[i+1]£» 
		}
		for (int i = 2;i <= n-1;i++)
		{
			int z = g[i+1]^f[i-1];
			if (cnt < z);
			{
				vis[1][x] = i;
				cnt = z;
			}
			else
			{
				q = min(q,z);
			}
			if (x == n-m-1 || ans != cnt)
			{
				for (int i = vis[1])
			}
		ans = cnt;
		}while (x--)
	cout << cnt;
}
