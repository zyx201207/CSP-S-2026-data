#include <bits/stdc++.h>
using namespace std;
#ifdef W_DEBUG
#define DOUT(x...) cerr << __FILE__ << ":" << __LINE__ <<":   " << x << endl
#else
#define DOUT(...) void(0)
#endif
using ll = long long;
namespace sub1
{
    struct Node
    {
	ll l, r;
	char x;
    };
void slove()
{
    ll n;
    cin >> n;
    vector<Node> a(n);
    ll l = 0;
    ll len = 0;
    for(ll i = 1; i <= n; ++i)
    {
	ll x;
	char c;
	cin >> x >> c;
	a[i - 1].l = len + 1;
	a[i - 1].r = len + x;
	a[i - 1].x = c;
	len += x;
    }
   
    l = 0;
    ll r = n - 1;
    ll ans = 0;
    ll flag = 0;
    while(l < n and r >= 0 and l < r)
    {
	ll rl =  len + 1 - a[r].r;
	ll rr = len + 1 - a[r].l;
	ll lel = a[l].l;
	ll lr = a[l].r;
	if(flag)
	{
	    if(l == n - 1)
	    {
		--r;
	    }
	    else if(lr >= len + 1 - a[r - 1].r)
	    {
		--r;
	    }
	    else
	    {
		++l;
		flag = 0;
		continue;
	    }
	}
	else
	{
	    while(lel > rr)
	    {
		--r;
		if(r < 0)
		{
		    break;
		}
		rl = len + 1 - a[r].r;
		rr = len + 1 - a[r].l;
	    }
	}
	flag = 1;
/*	while(lel > rr)
	{
	    ++l;
	    if(l >= n)
	    {
		break;
	    }
	    lel = a[l].l;
	    lr = a[l].r;
	}
*/	

	if(r < 0 or lel > rr)
	{
	    break;
	}
	DOUT(l << ' ' << r);
	ll tlen = min(lr, rr) - max(rl, lel) + 1;
//	DOUT(lr<<' '<<rr <<' '<<rl<<' '<<lel << a[l].x << a[r].x);
//	DOUT(min(lr, rr) << ' ' << max(rl, lel) );
//	DOUT(tlen);
	if(a[l].x != a[r].x)
	{
	    ans += tlen;
	}
//	DOUT(l << ' ' << r);
    }
    cout << ans;
}
}
namespace sub2
{
    struct Node
    {
	ll l, r;
	char x;
    };
void slove()
{
    ll n;
    cin >> n;
    vector<Node> a(n);
    ll l = 0;
    ll len = 0;
    for(ll i = 1; i <= n; ++i)
    {
	ll x;
	char c;
	cin >> x >> c;
	a[i - 1].l = len + 1;
	a[i - 1].r = len + x;
	a[i - 1].x = c;
	len += x;
    }
   
    l = 0;
    ll r = n - 1;
    ll ans = 0;
    while(l < n and r >= 0 and l < r)
    {
	{
	ll rl =  len + 1 - a[r].r;
	ll rr = len + 1 - a[r].l;
	ll lel = a[l].l;
	ll lr = a[l].r;
	while(lel > rr)
	{
	    --r;
	    if(r < 0)
	    {
		break;
	    }
	    rl = len + 1 - a[r].r;
	    rr = len + 1 - a[r].l;
	}
	if(r < 0 or lel > rr)
	{
	    break;
	}
	
	DOUT(l << ' ' << r);
	ll tlen = min(lr, rr) - max(rl, lel) + 1;
	if(a[l].x != a[r].x)
	{
	    ans += tlen;
	}
	}
	while(true)
	{
	    ll rl =  len + 1 - a[r].r;
	    ll rr = len + 1 - a[r].l;
	    ll lel = a[l].l;
	    ll lr = a[l].r;
	    if(l == n - 1)
	    {
		--r;
	    }
	    else if(lr >= len + 1 - a[r - 1].r)
	    {
		--r;
	    }
	    else
	    {
		++l;
		break;
	    }
	    if(r < 0 or lel > rr)
	    {
		break;
	    }
	    DOUT(l << ' ' << r);
	    ll tlen = min(lr, rr) - max(rl, lel) + 1;
	    if(a[l].x != a[r].x)
	    {
		ans += tlen;
	    }
	}
	++l;
    }
    cout << ans;
    
}
}
namespace sub3
{
    void slove()
    {
	string a;
	ll n;
	cin >> n;
	while(n--)
	{
	    ll x;
	    char c;
	    cin >> x >> c;
	    while(x--)
	    {
		a.push_back(c);
	    }
	}
	ll ans = 0;
	for(ll l = 0, r = a.size() - 1; l <= r; ++l,--r)
	{
	    ans += (a[l] != a[r]);
	}
	cout << ans;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "string"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    sub3::slove();
} 
