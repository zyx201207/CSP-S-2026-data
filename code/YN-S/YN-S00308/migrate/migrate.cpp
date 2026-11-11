#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7;
int len, n, d, c, t, cntt;
ll dis[maxn], yuan[maxn];
int head[maxn];
bool vis[maxn], viss[maxn];

struct op {
	int v, w, nxt;
} a[maxn];

void init(int u, int v, int w) {
	a[++len] = {v, w, head[u]};
	head[u] = len;
}

void dj(int s) {
	cntt = 0;
	memset(viss, 0, sizeof(viss));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<ll, int>> q;
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int num = q.top().second;
		ll est = q.top().first;
		q.pop();
		if (vis[num])
			continue;
		for (int i = head[num]; i; i = a[i].nxt) {
			int v = a[i].v;
			if (!vis[v] && dis[v] > v + est) {
				dis[v] = v + est;
				q.push({-dis[v], v});
				if (viss[v]) {
					viss[v] = 0;
					cntt--;
				}
			} else if (dis[v] == v + est) {
				cntt++;
				viss[v] = 1;
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cntt = 0;

		memset(a, 0, sizeof(a));

		memset(head, 0, sizeof(head));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> yuan[i];
			int j = i;
			while (yuan[i] - yuan[j - 1] <= d && j - 1 >= 1) {
				j--;
				init(i, j, 1);
				init(j, i, 1);
			}
		}
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			dj(i);
			maxx = max(maxx, cntt);
		}
		cout << maxx << "\n";
	}



	return 0;
}