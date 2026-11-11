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
    ll cc, n, m, d, q;
    cin >> cc >> n >> m >> d >> q;
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, 4e18));
    vector<ll> c(m + 1);
    for(ll i = 1; i <= m; ++i)
    {
	cin >> c[i];
    }
    DOUT("OK");
    vector<vector<pair<ll, ll>>> gt(m + 1);
    for(ll i = 1; i <= n; ++i)
    {
//	DOUT(g.size() << ' ' << i);
//	DOUT(g[i].size() << ' ' << i);
	g[i][i] = 0;
	ll k;
	cin >> k;
	for(ll j = 1; j <= k; ++j)
	{
	    ll a, t;
	    cin  >> a >> t;
//	    DOUT(gt.size() << ' ' <<  a);
	    gt[a].push_back({i, t});
	}
	
    }
    DOUT("OK");
    for(ll i = 1; i <= m; ++i)
    {
	for(ll j = 0; j < gt[i].size(); ++j)
	{
	    for(ll k = j + 1; k < gt[i].size(); ++k)
	    {
		ll x1 = gt[i][j].first;
		ll x2 = gt[i][k].first;
		g[x1][x2] = gt[i][k].second + gt[i][j].second;
		g[x2][x1] = gt[i][k].second + gt[i][j].second;
	    }
	}
    }
    DOUT("OK");
    for(ll k = 1; k <= n; ++k)
    {
	for(ll i = 1; i <= n; ++i)
	{
	    for(ll j = i + 1; j <= n; ++j)
	    {
		if(g[i][j] > g[i][k] + g[j][k])
		{
		    g[i][j] = g[i][k] + g[j][k];
		    g[j][i] = g[i][j];
		}
	    }
	}
    }
    DOUT("OK");
    while(q--)
    {
	ll x, y;
	cin >> x >> y;
	ll ans1 = c[x] + c[y];
	ll ans2 = 4e18;
	for(auto i : gt[x])
	{
	    for(auto j : gt[y])
	    {
		ll x1 = i.first;
		ll x2 = j.first;
		ans2 = min(ans2, g[x1][x2] + i.second + j.second);
	    }
	}
	cout << ans1 + ans2 << '\n';
    }
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "subway"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    sub1::solve();
}
