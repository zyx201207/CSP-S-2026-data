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
struct Trie
{
    struct Node
    {
	ll cnt = 0;
	ll s[2] = {};
    };
    vector<Node> a;
    Trie()
    {
	a.resize(2);
    }
    void ins(ll x)
    {
	ll p = 1;
	a[p].cnt++;
	for(ll i = 31; i >=0; i--)
	{
	    ll t = (x >> i)&1;
//	    DOUT(a.size() << ' ' << p);
	    if(a[p].s[t] == 0)
	    {
		a.emplace_back();
		a[p].s[t] = a.size() - 1;
	    }
	    p = a[p].s[t];
	    a[p].cnt++;
	}
    }
    ll find(ll m)
    {
	vector<ll>p;
	p.push_back(1);
	ll ans = 0;
	DOUT(((1 << 31) >= 1));
	for(ll i = (1ll << 31); i >= 1; i >>= 1)
	{
	    DOUT(i / 2);
	    ll c1 = 0, c2 = 0;
	    vector<ll>  pp1, pp2;
	    for(auto j : p)
	    {
		ll p1 = a[j].s[1];
		ll p2 = a[j].s[0];
		//	DOUT("[p1]" << p1 << ' ' << a[p1].cnt);
		//	DOUT("[p2]" << p2 << ' ' << a[p2].cnt);
		if(p1 != 0)
		{
		    pp1.push_back(p1);
		    c1 += a[p1].cnt;
		}
		if(p2 != 0)
		{
		    pp2.push_back(p2);
		    c2 += a[p2].cnt;
		}
	    }
	    if(c1 >= m)
	    {
		ans += i;
	    }
	    else
	    {
		for(auto i : pp2)
		{
		    pp1.push_back(i);
		}
	    }
	    swap(p, pp1);
	}
	return ans;
    }
};
void solve()
{
    ll n, m;
    cin >> n >> m;
    Trie trie;
    while(n--)
    {
	ll x;
	cin >> x;
	trie.ins(x);
    }
    DOUT(1);
    cout << trie.find(m);
}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    #define W_N "and"
    freopen(W_N ".in", "r", stdin);
    freopen(W_N ".out", "w", stdout);
    sub1::solve();
}
