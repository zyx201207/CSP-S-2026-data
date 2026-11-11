#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 1e3 + 10;
ll n, m;
vector<ll> h[N];
ll fa[N];
void dfs_init(ll x, ll fa)
{
	::fa[x] = fa;
	for(auto y : h[x]) if(y != fa) dfs_init(y, x);
}
ll bson, mid, ned;
pair<ll, ll> zy;
void dfs1(ll x, ll fa, ll len = 0)
{
	if(len > zy.second) zy = {x, len};
	for(auto y : h[x]) if(y != fa)
		{
			if(x == bson && y == ::fa[bson]) continue;
			if(y == bson && x == ::fa[bson]) continue;
			dfs1(y, x, len + 1);
		}
}
vector<ll> lj;
bool dfs2(ll x, ll fa, ll t)
{
	lj.push_back(x);
	if(x == t) return 1;
	for(auto y : h[x]) if(y != fa)
		{
			if(x == bson && y == ::fa[bson]) continue;
			if(y == bson && x == ::fa[bson]) continue;
			if(dfs2(y, x, t)) return 1;
		}
	lj.pop_back();
	return 0;
}

ll dep[N];
ll gdep = 1;
void dfs4(ll x, ll fa)
{
	dep[x] = dep[fa] + 1;
	for(auto y : h[x]) if(y != fa)
		{
			if(x == bson && y == ::fa[bson]) continue;
			if(y == bson && x == ::fa[bson]) continue;
			dfs4(y, x);

		}
}
void dfs5(ll x, ll fa)
{
	if(dep[x] - gdep > mid)
	{
		gdep++;
		ned++;
	}
	for(auto y : h[x]) if(y != fa)
		{
			if(x == bson && y == ::fa[bson]) continue;
			if(y == bson && x == ::fa[bson]) continue;
			dfs5(y, x);
			gdep = min(gdep, dep[x]);
		}
}
void dfs3(ll bg)
{
	dfs4(bg, 0);
	gdep = 0;
	ned = 0;
	dfs5(bg, 0);
}
ll calc(ll rt)
{
	zy = {0, -INF};
	dfs1(rt, 0);
	ll x = zy.first;
	zy = {0, -INF};
	dfs1(x, 0);
	lj.clear();
	dfs2(x, 0, zy.first);
	if(lj.size() % 2 == 1)
	{
		ned = 0;
		dfs3(lj[lj.size() / 2 + 1 - 1]);
		return ned;
	}
	else
	{
		ned = 0;
		dfs3(lj[lj.size() / 2 - 1]);
		ll t = ned;
		ned = 0;
		dfs3(lj[lj.size() / 2 + 1 - 1]);
		return min(t, ned);
	}
}
bool check()
{
	f(i, 2, n)
	{
		// ¶ÏµôµÄ¶ù×Ó
		bson = i;
//		ned = 0;
		ll t = calc(i);
//		ned = 0;
		ll t2 = calc(fa[i]);
		if(t2 + t <= m) {
		return 1;}
	}
	bson = 0;
//	ned = 0;
	if(calc(1) <= m) return 1;
	return 0;
}
void sov()
{
	cin >> n >> m;
	f(i, 1, n) 
	{
		vector<ll> t;
		swap(h[i], t);
	}
	f(i, 2, n)
	{
		ll x, y;
		cin >> x >> y;
		h[x].push_back(y), h[y].push_back(x);
	}
	if(n == m) return cout << 0 << '\n', void();
	dfs_init(1, 0);
	ll l = 1, r = n, mid, ans; 


	while(l <= r)
	{
		mid = (l + r) / 2;
		::mid = mid;
		ll t = check();
		if(t)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while(t--) sov();

	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
