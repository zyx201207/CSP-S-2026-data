#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
const int INF = 1e18;
int c, n, m, d, q;
int w[N], k[N], a[N], t[N], cnt1, cnt2;
struct node {
	int to, nxt, w;
} e[(N << 1) + N];
int head[N << 1], tot;
inline void add(int u, int v, int w) {
	e[++tot] = {v, head[u], w};
	head[u] = tot;
	return;
}
struct edge {
	int u, w;
	bool operator < (const edge &now) const {
		return w > now.w;
	}
};
bool vt[N << 1];
int deep[N << 1];
inline void dij(int s) {
	priority_queue<edge> q;
	for(int i = 1; i <= cnt1 + n; i++) deep[i] = INF;
	q.push({s, 0});
	deep[s] = 0;
	while(!q.empty()) {
		auto now = q.top();
		q.pop();
		int u = now.u;
		vt[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(vt[v]) continue;
			if(deep[v] > deep[u] + e[i].w) {
				deep[v] = deep[u] + e[i].w;
//				cout << deep[v] << '\n';
				q.push({v, deep[v]});
			}
		}
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) cin >> a[cnt1 + j] >> t[cnt1 + j];
		cnt1 += k[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k[i]; j++) {
			add(a[cnt2 + j], cnt1 + i, t[cnt2 + j]);
			add(cnt1 + i, a[cnt2 + j], t[cnt2 + j]);
		}
		cnt2 += k[i];
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		memset(vt, 0, sizeof(vt));
		memset(deep, 0, sizeof(deep));
		dij(x);
//		for(int i = 1; i <= n + m; i++) cout << deep[i] << ' ';
		cout << w[x] + deep[y] + w[y] << '\n';
	}
	return 0;
}