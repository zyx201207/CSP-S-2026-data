#include <bits/stdc++.h>
using namespace std;
#define ll int
#define for1(i,a,b) for(ll i=(a);i<=(b);++i)
#define for0(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N = 2e4+10, M = 510, K = 1e5+10;
const ll MOD = 0, INF = 1e9;

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

ll c, n, m, d, o, ans[K];
struct node{
	ll id, bh; // 第几个号，位于第几个
};
vector <node> e[N];
struct st1{
	ll s, t, id;
	bool operator < (const st1 &_) const {
		return s < _.s;
	}
}q[K];
ll w[N], k[M];
int t[M][N], a[M][N];
struct st2{
	ll u, p;
	bool operator < (const st2 &_) const {
		return p > _.p;
	}
};
priority_queue <st2> p;
ll dp[N];

inline void dij (ll u){
	while (!p.empty ()) p.pop ();
	for1 (i, 1, m) dp[i] = INF;
	p.push ({u, 0});
	dp[u] = 0;
	while (!p.empty ()){
		st2 tmp = p.top ();
		p.pop ();
		ll u = tmp.u, w = tmp.p;
		if (w != dp[u]) continue;
		for (node i : e[u]){
			ll id = i.id, bh = i.bh;
			for1 (j, bh+1, k[id]){
				ll nw = w+t[id][bh]+t[id][j];
				if (nw >= dp[a[id][j]]) continue;
				dp[a[id][j]] = nw;
				p.push ({a[id][j], nw});
			}
		}
	}
}

signed main (){
	freopen ("subway.in", "r", stdin);
//	freopen ("subway5.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
//	ios::sync_with_stdio (0);
//	cin.tie (0), cout.tie (0);
	c = read (), n = read (), m = read (), d = read (), o = read ();
	for1 (i, 1, m){
		w[i] = read ();
	}
	ll cnt = 0;
	for1 (i, 1, n){
		k[i] = read ();
		for1 (j, 1, k[i]){
			a[i][j] = read (), t[i][j] = read ();
			e[a[i][j]].push_back ({i, j});
		}
	}
	for1 (i, 1, o){
		q[i].s = read (), q[i].t = read ();
		if (q[i].t < q[i].s) swap (q[i].s, q[i].t);
		q[i].id = i;
	}
	sort (q+1, q+o+1);
	for1 (i, 1, o){
		if (q[i].s == q[i-1].s) continue;
		dij (q[i].s);
		for1 (j, i, o){
			if (q[j].s != q[j-1].s and i != j) break;
			ans[q[j].id] = dp[q[j].t];
			ans[q[j].id] += w[q[j].s]+w[q[j].t];
		}
	}
	for1 (i, 1, o){
		write (ans[i]);
		puts ("");
	}
	return 0;
}
