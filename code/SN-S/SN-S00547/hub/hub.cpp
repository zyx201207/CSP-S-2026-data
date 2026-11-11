#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 110;
ll c, T, n, k, ans = 110, f[N][N], color[N], u[N], v[N];
vector<ll> G[N], d[N];
bool st[N], vis[N];
void dfs2(ll x)
{
	for(ll i = 0; i < G[x].size(); i ++)
	{
		ll to = G[x][i];
		if(vis[to]) continue;
		color[to] = color[x];
		vis[to] = true;
		dfs2(to);
	}
	return;
}
void check()
{
	for(ll i = 1; i <= n; i ++) color[i] = 0;
	for(ll i = 1; i <= n; i ++) G[i].clear();
	for(ll i = 1; i < n; i ++)
	{
		if(st[u[i]] && st[v[i]])
		{
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
		}
	}
	ll res = 0;
	memset(vis, false, sizeof vis);
	for(ll i = 1; i <= n; i ++)
	{
		if(st[i] && !vis[i])
		{
			res ++;
			vis[i] = true;
			color[i] = res;
			dfs2(i);
		}
	}
	if(res > 2) return;
	ll now = 0;
	for(ll i = 1; i <= n; i ++)
	{
		ll res = 110;
		for(ll j = 1; j <= n; j ++)
		{
			if(st[j]) res = min(res, f[i][j]);
		}
		now = max(now, res);
	}
	ans = min(ans, now);
	return;
}
void dfs(ll x, ll now)
{
	if(x == n + 1)
	{
		ll cnt = 0;
		for(ll i = 1; i <= n; i ++)
		{
			if(st[i]) cnt ++;
		}
		if(cnt != k) return;
		check();
		return;
	}
	st[x] = true;
	dfs(x + 1, now + 1);
	st[x] = false;
	dfs(x + 1, now);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T --)
	{
		ans = 110;
		cin >> n >> k;
		memset(f, 0x3f, sizeof f);
		memset(st, false, sizeof st);
		for(ll i = 1; i <= n; i ++) d[i].clear();
		for(ll i = 1; i < n; i ++)
		{
			cin >> u[i] >> v[i];
			d[u[i]].push_back(v[i]);
			d[v[i]].push_back(u[i]);
		}
		for(ll i = 1; i <= n; i ++) f[i][i] = 0;
		for(ll i = 1; i <= n; i ++)
		{
			queue<ll> q;
			q.push(i);
			while(!q.empty())
			{
				ll t = q.front();
				q.pop();
				for(ll j = 0; j < d[t].size(); j ++)
				{
					ll to = d[t][j];
					if(f[i][to] > f[i][t] + 1)
					{
						f[i][to] = f[i][t] + 1;
						q.push(to);
					}
				}
			}
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	
	return 0;
}
