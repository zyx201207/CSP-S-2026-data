#include<bits/stdc++.h>
using namespace std;
#ifdef W_DEBUG
#define DOUT(x...) cerr<<__FILE__ << ":" << __LINE__ << ": " << x << endl
#else
#define DOUT(...) void(0)
#endif
using ll = long long;
namespace sub1
{

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> g(n + 1);
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1));
    for(ll i = 1; i < n; ++i)
    {
	ll u, v;
	cin >> u >> v;
	g[u].push_back(v);
	g[v].push_back(u);
    }
    auto dfs = [&](auto&& self, ll u, ll fa, ll ff, ll ds)->void
	       {
		   dis[ff][u] = ds;
		   for(auto i : g[u])
		   {
		       if(i != fa)
		       {
			   self(self, i, u, ff, ds + 1);
		       }
		   }
	       };
    for(ll i = 1; i <= n; ++i)
    {
	dfs(dfs, i, i, i, 0);
    }
    for(ll i = 1; i <= n; ++i)
    {
	for(ll j = 1; j <= n; ++j)
	{
	    cerr << dis[i][j] << ' ';
	}
	cerr << endl;
    }
    if(k == 2)
    {
	ll ans = INT_MAX;
	for(ll i = 1; i <= n; ++i)
	{
	    for(ll j = i + 1; j <= n; ++j)
	    {
		ll mxdis = 0;
		for(ll k = 0; k <= n; ++k)
		{
		    mxdis = max(mxdis, min(dis[k][i], dis[k][j]));
		}
		DOUT(i << ' ' << j << ' '<< mxdis);
		ans = min(ans, mxdis);
	    }
	}
	cout << ans << '\n';
	return;
    }
    ll ans = INT_MAX;
    for(ll i = 0; i < (1 << n); ++i)
    {
	vector<ll> a;
	set<ll> a2;
	for(ll j = 1; j <= n; ++j)
	{
	    if((i >> (j - 1)) & 1)
	    {
		a.push_back(j);
		a2.insert(j);
	    }
	}
	if(a.size() != k)
	{
	    continue;
	}
	vector<ll> vis(n + 1);
	auto Dfs = [&](auto&& self, ll x, ll fa) -> void
		   {
		       vis[x] = 1;
		       for(auto i : g[x])
		       {
			   if(i != fa and a2.count(i))
			   {
			       self(self, i, x);
			   }
		       }
		   };
	ll cnt = 0;
	for(auto i : a)
	{
	    if(not vis[i])
	    {
		if(a2.count(i))
		{
		    Dfs(Dfs, i, i);
		    ++cnt;
		}
	    }
	}
	if(cnt > 2)
	{
	    continue;
	}
	ll maxdis = 0;
	for(ll i = 1; i <= n; ++i)
	{
	    ll mindis = INT_MAX;
	    for(auto j:a)
	    {
		mindis = min(mindis, dis[j][i]);
	    }
	    maxdis = max(maxdis, mindis);
	}
	for(auto i : a)
	{
	    cerr << i << ' ';
	}
	cerr << ":   " << maxdis << '\n';
	ans = min(ans, maxdis);
	DOUT(ans);
    }
    cout << ans << '\n';
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "hub"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    ll cc, t;
    cin >> cc >> t;
    while(t--)
	sub1::solve();
}

