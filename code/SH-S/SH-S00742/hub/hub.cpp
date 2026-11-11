#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll point_id, t;
ll n, k;
vector<ll> g[1000006];
bool u[1000006];
bool vis[1000006];
int LuO, gU, U, iD = 1029108; 
ll chk_dfs(ll p, ll f)
{
	ll num = 0, m = 0;
	for(int cur : g[p])
	{
		if(cur == f)
			continue;
		ll tmp = chk_dfs(cur, p);
		num += tmp;
		if(tmp)
			m++;
	}
	if(u[p])
		return min(num - m, 1LL);
	else
		return num;
}
ll chk()
{
	if(chk_dfs(1, 0) > 2)
		return 1e18;
	ll ans = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		if(u[i] || vis[i]) continue;
		queue<pair<ll, ll>> q;
		q.push({i, 0});
		vis[i] = 1;
		while(!q.empty())
		{
			auto tp = q.front();
			q.pop();
			if(u[tp.first])
			{
				ans = max(ans, tp.second);
				break;
			}
			vis[tp.first] = 1;
			for(int cur : g[tp.first])
				if(!vis[cur])
					vis[cur] = 1, q.push({cur, tp.second + 1});
		}
	}
	return ans;
}
ll dfs(ll p, ll num)
{
	if(p == n + 1)
		return (num == k ? chk() : 1e18);
	ll ans = dfs(p + 1, num);
	u[p] = 1;
	ans = max(ans, dfs(p + 1, num + 1));
	u[p] = 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> point_id >> t;
	while(t--)
	{
		cin >> n >> k;
		for(ll i = 1; i <= n; i++)
			g[i].clear();
		for(ll i = 1, u, v; i < n; i++)
			cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
		cout << dfs(1, 0) << endl;
	}
	return 0;
}

