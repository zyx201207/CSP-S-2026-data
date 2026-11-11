#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,w[500005],flag[500005],vis[500005];
vector <array<int, 2> > hall[500005];
vector <array<int, 2> > sta[500005];
vector <array<int, 2> > ve[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int a;
			cin >> a >> t;
			sta[a].push_back({i,t});
			hall[i].push_back({a,t});
			flag[a]++;
		}
	}
	for (int i = 1;i <= m;i++)//O(md*logd)
	{
		if (vis[i])
		{
			continue;
		}
		vis[i] = 1;
		int len = sta[i].size();
		if (len == 1)
		{
			continue;
		}
		sort(sta[i].begin(),sta[i].end());
		for (auto v : sta[i])
		{
			int s = v[0],t = v[1];
			for (auto h : hall[s])
			{
				int u = h[0];
				if (u == s)
				{
					continue;
				}
				vis[u] = 1;
				ve[i].push_back({u,t + h[1]});
			}
		}
	}
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		cout << w[x] + (n - 1) * t << "\n"; 
	}
	return 0;
}
