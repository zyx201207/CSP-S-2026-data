#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
const int INF = 1e18;
int n, d;
int x[N];
struct node {
	int to, nxt, w;
} e[N << 1];
int head[N], tot;
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
bool vt[N];
int deep[N], cnt[N];
inline void dij(int s) {
	priority_queue<edge> q;
	for(int i = 1; i <= n; i++) deep[i] = INF;
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
			if(deep[v] == deep[u] + e[i].w) cnt[v] = cnt[u] + 1;
			else if(deep[v] > deep[u] + e[i].w) {
				cnt[v] = 0;
				deep[v] = deep[u] + e[i].w;
				q.push({v, deep[v]});
			}
		}
	}
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		bool ok = 1;
		int c = x[2] - x[1];
		for(int i = 2; i < n; i++) {
			if(c != x[i + 1] - x[i]) {
				ok = 0;
				break;
			}
		}
		if(ok == 1) cout << n - d - 1 << '\n';
		else {
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					if(x[j] - x[i] <= d) add(i, j, x[j] - x[i]);
					else break;
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				memset(vt, 0, sizeof(vt));
				dij(i);
				for(int j = i + 1; j <= n; j++) if(cnt[j] == 2) ans++;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}