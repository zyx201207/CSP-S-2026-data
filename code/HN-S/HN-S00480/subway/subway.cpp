#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const ll N=5e5+5;
struct p
{
	ll a, t;
};
ll c, n, m, d, q;
ll w[N];
vector<p> g[N], g2[N];
ll x, y;
ll vis[N];
ll dis[N];
void dfs(ll u, ll st)
{
	dis[u]=min(dis[u], st);
	for(ll i=0; i<g2[u].size(); i++)
	{
		ll sl=g2[u][i].a, s=g2[u][i].t;
		for(ll j=0; j<g[sl].size(); j++)
		{
			ll v=g[sl][j].a;
			if(vis[v] || dis[v]<st+g[sl][j].t+s) continue;
			vis[v]=1;
			dfs(v, st+g[sl][j].t+s);
			vis[v]=0;
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> d >>q;
	for(ll i=1; i<=n; i++) cin >> w[i];
	for(ll i=1; i<=m; i++)
	{
		ll k;
		cin >> k;
		for(ll j=1; j<=k; j++)
		{
			ll a, t;
			cin >> a >> t;
			g[i].push_back(p{a, t});
			g2[a].push_back(p{i, t});
		}
	}
	while(q--)
	{
		cin >> x >> y;
		fill(dis+1, dis+n+1, 1e18);
		dfs(x, 0);
		cout << dis[y]+w[x]+w[y] << endl;
	}
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
