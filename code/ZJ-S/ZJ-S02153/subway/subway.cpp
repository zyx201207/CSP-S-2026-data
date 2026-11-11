#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M = 2e4 + 7, N = 5e2 + 7, M1 = 5e5 + 7;
ll w[M], n, m, k[N], Q, c, d;
ll head[M], nxt[M1 << 1], to[M1 << 1], val[M1 << 1], tot, cnt;
void add(ll u, ll v, ll w) {
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
struct node{
	ll p, dis;
	bool operator<(const node a)const{
		return dis > a.dis;
	}
};
priority_queue<node> q;
ll dis[M], vis[M];
void query(ll s, ll t) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0;
	q.push((node){s, 0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.p]) continue;
		vis[t.p] = 1;
		for (ll i = head[t.p]; i; i = nxt[i]) {
			ll tp = to[i];
			if (dis[tp] > dis[t.p] + val[i]) {
				dis[tp] = dis[t.p] + val[i];
				q.push((node){tp, dis[tp]});
			}
		}
	}
	cout << dis[t] + w[s] + w[t] << "\n";
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (ll i = 1; i <= m; i++)
		cin >> w[i];
	cnt = m;
	for (ll i = 1; i <= n; i++) {
		cin >> k[i];
		for (ll j = 1; j <= k[i]; j++) {
			cnt++;
			if (j >= 2) add(cnt, cnt - 1, 0), add(cnt - 1, cnt, 0);
			ll u, w;
			cin >> u >> w;
			add(u, cnt, w); add(cnt, u, w);
		}
	}
	while (Q--) {
		ll s, t;
		cin >> s >> t;
		query(s, t);
	}
	return 0;
}