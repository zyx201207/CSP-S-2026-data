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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; ++i)
    {
	cin >> a[i];
    }
    sort(++a.begin(), a.end());
    vector<ll> sum(n + 1);
    for(ll i = 1; i <= n; ++i)
    {
	sum[i] = sum[i - 1] + a[i];
    }
    auto check = [&](ll l, ll r)
    {
	return (a[r] * (r - l + 1) - sum[r] + sum[l - 1]) <= m;
    };
    ll ans = 0;
    for(ll i = 1; i <= n; ++i)
    {
	ll l = i, r = n;
	while(l < r)
	{
	    ll m = l + (r - l) / 2;
	    if(check(i, m))
	    {
		l = m + 1;
	    }
	    else
	    {
		r = m;
	    }
	}
	ans = max(ans, (l - i + 1));
    }
    cout << ans - 1;
    // i~j    a[j] * (j - i + 1) - sjm(k:i~j) a[k]
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "crystal"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    sub1::solve();
}
