#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e3 + 10;
const ll INF = 1e18;

ll __, _, n, d, x[N];

// 需要清空 
vector <ll> e[N];
ll dis[N][N], vis[N][N], cnt[N][N];

void bfs(ll s) {
	queue <ll> q;
	q.push(s);
	dis[s][s] = 0;
	
	while (q.size()) {
		ll u = q.front();
		q.pop();
		
		if (vis[s][u]) continue;
		vis[s][u] = 1;
		
		for (ll v : e[u]) {
			if (dis[s][v] == dis[s][u] + 1) cnt[s][v] ++;
			if (dis[s][v] > dis[s][u] + 1) {
				dis[s][v] = dis[s][u] + 1;
				cnt[s][v] ++;
				q.push(v);
			}
		}
	}
}

void add(ll u, ll v) {
	e[u].push_back(v);
	e[v].push_back(u);
}

void clear(ll n) {
	for (ll i = 1; i <= n; i ++) e[i].clear();
	for (ll i = 1; i <= n; i ++)
		for (ll j = 1; j <= n; j ++) {
			dis[i][j] = INF;
			vis[i][j] = cnt[i][j] = 0;
		}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> __ >> _;
	while (_ --)	// O(tn^2) <24pts 
	{
		cin >> n >> d;
		clear(n);
		for (ll i = 1; i <= n; i ++) cin >> x[i];
		for (ll i = 1; i <= n; i ++) {
			for (ll j = 1; j <= n; j ++) {
				if (i == j) continue;
				ll p = x[i] - x[j];
				if (p < 0) p = -p;
				if (p <= d) add(i, j);
			}
		}
		for (ll i = 1; i <= n; i ++) bfs(i);	// O(n^2)
		
//		// debug
//		for (ll i = 1; i <= n; i ++) 
//			for (ll j = 1; j <= n; j ++) {
//				cout << i << ' '<< j << ' ' << dis[i][j] << ' ' << cnt[i][j] << endl;
//			}
		
		ll ans = 0;
		for (ll i = 1; i <= n; i ++) 
			for (ll j = 1; j < i; j ++) 
				ans += (cnt[i][j] == 4);
		cout << ans << endl;
	}

	return 0;
}

// 40min 24pts 到手 
// 中间摆了一会儿，这个暴力很快就能写完
// 17:20 在做T4和写特殊性质之间徘徊 

// 17:26 完了大样例怎么没过 

// 17:36 别改T3这坨史了 

// 加油 相信自己
// 只要能过掉 T1 就行
// RP ++ for Cute_zsz


