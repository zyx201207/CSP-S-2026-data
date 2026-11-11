#include <bits/stdc++.h>
#define int long long
using namespace std;
const int CN = 1e6+6,inf = 0x3f3f3f3f3f3f3f3f;
int c,t,n,k,u,v,cnt0,cnt1,mx,mn,ans,dis[12][12];
bool f[12],vis[12];
vector <int> e[CN];
void dfs1(int x,int fa,int root)
{
	for (int y:e[x])
		if (y != fa)
		{
			dis[root][y] = dis[root][x]+1;
			dfs1(y,x,root);
		}
}
void dfs2(int x,int fa)
{
	vis[x] = 1;
	for (int y:e[x])
		if (y != fa && f[y])
			dfs2(y,x);
}
#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = inf;
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
			e[i].clear();
		for (int i = 1;i < n;i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (c <= 3)
		{
			for (int i = 1;i <= n;i++)
				dfs1(i,0,i);
			for (int i = 1;i < (1<<n);i++)
			{
				for (int j = 1;j <= n;j++)
					vis[j] = 0;
				cnt0 = cnt1 = 0;
				for (int j = 1;j <= n;j++)
				{
					f[j] = i&(1<<j-1);
					cnt0 += f[j];
					if (f[j] && !vis[j])
					{
						dfs2(j,0);
						cnt1++;
					}
				}
				if (cnt0 == k && cnt1 <= 2)
				{
					mx = 0;
					for (int j = 1;j <= n;j++)
					{
						mn = inf;
						for (int k = 1;k <= n;k++)
							if (f[k])
								mn = min(mn,dis[j][k]);
						mx = max(mx,mn);
					}
					ans = min(ans,mx);
				}
			}
			cout << ans << '\n';
			continue;
		}
		if (n == k)
		{
			cout << "0\n";
			continue;
		}
		(n /= 2) += 2;
		if (k >= n)
		{
			cout << "1\n";
			continue;
		}
		cout << (n-k-1)/4+1 << '\n';
	}
	return 0;
}