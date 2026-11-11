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
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n + 1);
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, 4e18));
    vector<vector<ll>> cnt(n + 1, vector<ll>(n + 1));
    ll ans = 0;
    for(ll i = 1; i <= n; ++i)
    {
	cin >> x[i];
	for(ll j = i - 1; j >= 1; --j)
	{
	    // j~i
	    if(x[i] - x[j] <= d)
	    {
		dis[j][i] = 1;
		cnt[j][i] = 1;
		continue;
	    }
	    for(ll k = i - 1; k > j; --k)
	    {
		if(x[i] - x[k] > d)
		{
		    break;
		}
		if(dis[j][k] + 1 < dis[j][i])
		{
		    dis[j][i] = dis[j][k] + 1;
		    cnt[j][i] = cnt[j][k];
		}
		else if(dis[j][k] + 1 == dis[j][i])
		{
		    cnt[j][i] += cnt[j][k];
		}
	    }
	    if(cnt[j][i] == 2)
	    {
		++ans;
	    }
	}
    }
    cout << ans << '\n';
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "migrate"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    ll cc, t;
    cin >> cc >> t;
    while(t--)
	sub1::solve();
}

