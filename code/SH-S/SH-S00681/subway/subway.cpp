#include<bits/stdc++.h>
#define ll long long
const int N = 505, M = 5e5 + 5;
using namespace std;
int c, n, m, D, Q;
ll s, t;
int a[M];
bool vis[N], pvis[M];
vector<pair<ll, ll>> e[N], p[M]; // e[i]表示第i辆地铁, p[i]表示第i个地铁站
ll dfs(int now, int end)
{
	ll res = 0x3f3f3f3f3f3f3f3f;
	if(pvis[now])
		return res;
	pvis[now] = 1;
	// for(auto [u, w] : p[now])
	for(int i = 0; i < (int)p[now].size(); i++)
	{
		ll u = p[now][i].first, w = p[now][i].second;
		if(vis[u])
			continue;
		vis[u] = 1;
		// for(auto [v, l] : e[u])
		for(int j = 0; j < (int)e[u].size(); j++)
		{
			ll v = e[u][j].first, l = e[u][j].second;
			if(v == end)
			{
				res = min(res, l + w);
				break;
			}
			else
				res = min(dfs(v, end) + w + l, res);
		}
	}
	return res;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		while(x--)
		{
			cin >> s >> t;
			e[i].push_back({s, t});
			p[s].push_back({i, t});
		}
	}
	while(Q--)
	{
		cin >> s >> t;
		memset(vis, 0, sizeof(vis));
		memset(pvis, 0, sizeof(pvis));
		ll ans = dfs(s, t) + a[s] + a[t];
		cout << ans << '\n';
	}
 }
