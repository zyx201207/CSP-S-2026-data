#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(i,a,b) for(ll i=(a);i<=(b);++i)
#define for0(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N = 2e6+10, M = 0;
const ll MOD = 0, INF = 1e18;

inline ll read (){
	ll x = 0, f = 1; char op;
	do {op = getchar (); if (op == '-') f = -1;} while ('0' > op or op > '9');
	while ('0' <= op and op <= '9') x *= 10, x += op-'0', op = getchar ();
	return x*f;
}

inline void write (ll x){
	if (x < 0) putchar ('-'), x = -x;
	if (x > 9) write (x/10);
	putchar (x%10+'0');
}

ll c, t, n, d, a[N], dis[N], cnt[N], v, r[N]; // 最小步数与到达次数 

inline void dfs (ll u, ll stp){
	for0 (nxt, min (v, r[u]), u+1){
		if (!dis[nxt]) dis[nxt] = stp+1;
		if (stp+1 != dis[nxt]) continue;
		++ cnt[nxt];
		dfs (nxt, stp+1);
	}
}

signed main (){
	freopen ("migrate.in", "r", stdin);
//	freopen ("migrate3.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
//	ios::sync_with_stdio (0);
//	cin.tie (0), cout.tie (0);
	c = read (), t = read ();
	while (t --){
		n = read (), d = read ();
		for1 (i, 1, n){
			a[i] = read ();
		} 
		for1 (i, 1, n){
			r[i] = upper_bound (a+1, a+n+1, a[i]+d)-a;
			-- r[i];
		}
		ll res = 0;
		for1 (i, 1, n-2){
			v = n;
			dfs (i, 0);
			for1 (j, 1, n){
				if (cnt[j] == 2){
					++ res;
				}
			}
			for1 (k, i, n) dis[k] = cnt[k] = 0;
		}
		write (res);
		puts ("");
//		return 0;
	}
	return 0;
}
