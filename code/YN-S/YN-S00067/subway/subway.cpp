#include <bits/stdc++.h>
using namespace std;

struct node {
	long long x, y;
} e[500005];

struct note {
	long long v, w;
	friend bool operator < (note a, note b) {
		return a.w > b.w;
	}
} tmp;
int c, n, m, d, q;
long long w[500005], k[500005];
long long dis[500505];
bool vis[500505];
long long h[1000505], nxt[1000505], to[1000505], val[1000505];
int cnt = 0;

void add(int u, int v, int ww) {
	to[++cnt] = v;
	nxt[cnt] = h[u];
	val[cnt] = ww;
	h[u] = cnt;
}

bool cmp(node a, node b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

void di(int s, int end) {
	priority_queue < note > q;
	for (int i = 1; i <= m + n; i++) {
		dis[i] = 2000000000;
		vis[i] = 0;
	}
	dis[s] = 0;
	q.push({s, 0});
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		int u = tmp.v;
		if (u == end)
			break;
		if (vis[u])
			continue;
		if (u <= m)
			vis[u] = 1;
		for (int i = h[u]; i; i = nxt[i]) {
			int vv = to[i], ww = val[i];
			if (dis[vv] > dis[u] + ww) {
				dis[vv] = dis[u] + ww;
				tmp.v = vv;

				tmp.w = dis[vv];
				q.push(tmp);
			}
		}
	}
	cout << dis[end] + w[s] + w[end] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (k[i] == 1)
			continue;
		if (k[i] == 2) {
			long long a1, a2, t1, t2;
			cin >> a1 >> t1 >> a2 >> t2;
			add(a1, a2, t1 + t2);
			add(a2, a1, t1 + t2);
			continue;
		}
		for (long long j = 1; j <= k[i]; j++) {
			long long a, t;
			cin >> a >> t;
			add(m + i, a, t);
			add(a, m + i, t);
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		di(x, y);
	}
	return 0;
}