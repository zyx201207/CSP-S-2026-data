#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 5e5 + 10 + 500, M = 510;
ll c, n, m, lim, q;
ll a[N];
vector<pair<ll, ll>> h[M];
ll dis[M][M];
vector<pair<ll, ll>> b[N];

bitset<N> isok;
void dij(ll s, ll dis[])
{
	f(i, 1, m) dis[i] = INF, isok[i] = 0;
	dis[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, s});
	while(pq.size())
	{
		auto tmp = pq.top();
		pq.pop();
		ll x = tmp.second, len = tmp.first;
		if(isok[x]) continue;
		isok[x] = 1;
		dis[x] = len;
		for(auto it : h[x])
		{
			ll y = it.first, l2 = it.second;
			if(isok[y]) continue;
			pq.push({len + l2, y});
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>m>>n;
	cin>>lim>>q;
	f(i, 1, n) cin>>a[i];  
	f(i, 1, m)
	{
		ll nu;
		cin>>nu;
		while(nu--)
		{
			ll x, y;
			cin>>x>>y;
			b[x].push_back({i, y});
		}
	}
	f(i, 1, n)
	{
		for(ll _i = 0; _i <= (ll)b[i].size() - 1; _i++) for(ll _j = _i + 1; _j <= (ll)b[i].size() - 1; _j++)
		{
			ll x = b[i][_i].first, y = b[i][_j].first, len = b[i][_i].second + b[i][_j].second;
			if(x >= y) continue;
			h[x].push_back({y, len});
			h[y].push_back({x, len});
		}
	}
	f(i, 1, m) dij(i, dis[i]);
	f(i, 1, m) dij(i, dis[i]);
	while(q--)
	{
		ll x, y;
		cin>>x>>y;
		ll ans = INF;
		for(auto it1 : b[x]) 
			for(auto it2 : b[y]) if(dis[it1.first][it2.first] != INF) ans = min(ans, it1.second + dis[it1.first][it2.first] + it2.second);
		cout<<ans + a[x] + a[y]<<'\n';
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
