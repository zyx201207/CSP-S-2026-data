#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000005;
int a[N];
int c,T,n,d,mind = 2e9,sum;
void dfs1(int x,int y,int dis)
{
	if (x == y)
	{
		mind = min(mind,dis);
		return;
	}
	for (int i = x + 1;i <= y;i++)
		if (a[i] - a[x] <= d) dfs1(i,y,dis + 1);
}
void dfs2(int x,int y,int dis)
{
	if (dis > mind) return;
	if (x == y && dis == mind)
	{
		sum++;
		return;
	}
	if (x == y) return;
	for (int i = x + 1;i <= y;i++)
		if (a[i] - a[x] <= d) dfs2(i,y,dis + 1);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		scanf("%lld%lld",&n,&d);
		for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
		if (c == 0 || c == 11 || c == 12)
		{
			int x = a[2] - a[1];
			if (d < x * 2) cout << 0 << endl;
			else cout << max(n - d / x * 2 + 1,(long long)0) << endl;
		}
		else
		{
			int ans = 0;
			for (int i = 1;i <= n - 3;i++)
			{
				for (int j = i + 3;j <= n;j++)
				{
					if (a[j] - a[i] <= d) continue;
					sum = 0;
					dfs1(i,j,0);
					dfs2(i,j,0);
					if (sum == 2) ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
//16:11-18:15 16pts???
