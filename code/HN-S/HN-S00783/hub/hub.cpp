#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(i,a,b) for(ll i=(a);i<=(b);++i)
#define for0(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N = 1e6+10, M = 0;
const ll MOD = 0, INF = 1e18;

ll c, t, n, k, ans;
vector <ll> e[N];
ll dis[N];

inline void dfs (ll u, ll f, ll s){
	dis[u] = min (dis[u], s);
	for (ll v : e[u]){
		if (v == f) continue;
		dfs (v, u, s+1);
	}
}

inline ll check (ll a, ll b){
	for1 (i, 1, n) dis[i] = INF;
	dis[a] = dis[b] = 0;
	dfs (a, 0, 0);
	if (b) dfs (b, 0, 0);
	ll maxx = 0;
	for1 (i, 1, n){
		maxx = max (maxx, dis[i]);
	}
	return maxx;
} 

signed main (){
	freopen ("hub.in", "r", stdin);
//	freopen ("hub2.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >>c >>t;
	while (t --){
		cin >>n >>k;
		ans = INF;
		for1 (i, 1, n){
			e[i].clear ();
		}
		for1 (i, 1, n-1){
			ll u, v; cin >>u >>v;
			e[u].push_back (v);
			e[v].push_back (u); 
		}
		if (k == 1){
			for1 (i, 1, n){
				ans = min (check (i, 0), ans);
			}
		}
		else{
			for1 (i, 1, n-1){
				for1 (j, i+1, n){
					ans = min (check (i, j), ans);
				}
			}
		}
		cout <<ans <<'\n';
	} 
	return 0;
}

