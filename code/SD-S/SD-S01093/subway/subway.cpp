#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510;
const int M = 5e5 + 10;
typedef pair<int, int> pii;

struct Edge {
	int to, nxt, w;
};
Edge e[M * 50];
int head[M << 3], idx;

inline void addedge (int u, int v, int w) {
	e[++idx] = {v, head[u], w}, head[u] = idx;
	e[++idx] = {u, head[v], w}, head[v] = idx;
}

int c, n, m, d, q;
static int w[M], len[M];
vector<vector<int> > a, t;
vector<pii> qy[M];
long long ans[M];

struct Node {
	int u;
	long long w;
	const bool operator< (const Node & x) const {
		return w > x.w;
	}
};

bool f[M << 3];
long long dis[M << 3];
int cnt;
inline void dijkstra (int st) {
	priority_queue<Node> q;
	memset (f, 0, (cnt + 1) * sizeof (bool));
	memset (dis, 0x3f, (cnt + 1) * sizeof (long long));
	q.push(Node {st, 0});
	dis[st] = 0;
	while (!q.empty()) {
		Node h = q.top();
		q.pop();
		if (f[h.u]) continue;
		f[h.u] = 1;
		for (int i = head[h.u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > dis[h.u] + e[i].w)
				dis[v] = dis[h.u] + e[i].w, q.push (Node {v, dis[v]});
		}
	}
}

inline int read () {
	char ch = getchar();
	int f = 1, x = 0;
	while (!isdigit (ch))
		f = (ch == '-' ? -1 : 1), ch = getchar();
	while (isdigit (ch))
		x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
	return f * x;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);

	c = read (), n = read (), m = read (), d = read (), q = read ();
	for (int i = 1; i <= m; i++) w[i] = read ();

	a.resize(n + 1), t.resize(n + 1);
	cnt = m;
	for (int i = 1; i <= n; i++) {
		len[i] = read ();
		a[i].resize(len[i] + 1), t[i].resize(len[i] + 1);
		for (int j = 1; j <= len[i]; j++) {
			a[i][j] = read (), t[i][j] = read ();
			addedge (++cnt, a[i][j], t[i][j]);
			if (j - 1 >= 1)
				addedge (cnt, cnt - 1, 0);
		}
	}
//	cout << cnt << "\n";
	for (int i = 1; i <= q; i++) {
		int x, y;
		x = read(), y = read();
		qy[x].push_back({y, i});
	}
	for (int i = 1; i <= m; i++) {
		if (qy[i].empty()) continue;
		dijkstra (i);
		for (auto it:qy[i]) {
			int v = it.first, id = it.second;
			ans[id] = dis[v] + w[i] + w[v];
		}
	}
	for (int i = 1; i <= q; i++)
		printf ("%lld\n", ans[i]);
	return 0;
}

