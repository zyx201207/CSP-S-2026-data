#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
struct edge{
	int n, nxt;
} e[55];
struct node {
	int u, fa, n;
};
int head[15], tot;
void add(int u, int v) {
	e[++tot] = {v, head[u]};
	head[u] = tot;
} 
int n, k, p[15], vis[15];
int bfs(int u) {
	memset(vis, 0, sizeof vis);
	queue<node> q;
	q.push({u, 0, 0});
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if(p[now.u]) return now.n;
		vis[now.u] = 1;
		for(int i = head[now.u]; i; i = e[i].nxt) {
			int v = e[i].n;
			if(!vis[v]) q.push({v, now.u, now.n + 1});
		}
	}
}
void solve() {
	cin >> n >> k;
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		if(n <= 10) add(u, v), add(v, u);
	}
	if(n > 10) return;
	int pt = pow(2, n), ans = n;
	rep(i, 1, pt - 1) {
		memset(p, 0, sizeof p); 
		int cnt = 0, x = i, l = 1;
		while(x) {
			if(x & 1) cnt++, p[l] = 1;
			l++, x >>= 1;
		}
		int sum = 0;
		if(cnt == k) {
			rep(i, 1, n) sum = max(sum, bfs(i));
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
