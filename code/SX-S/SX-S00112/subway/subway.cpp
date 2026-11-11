#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt, c, d, p, n, m, a, t, jinchu[1005], k, fa[1005], sum, x, y, num, f;
int first[1005], book[1005];
queue< pair<int, int>  > q;

struct node {
	int u, v, w;
} edge[20005];

struct node1 {
	int to, w, next;
} edge1[20005];

inline bool cmp(node x, node y) {
	return x.w < y.w;
}

inline int bfs(int s, int t) {
	q.push(make_pair(s, 0));
	book[s] = 1;
	while (!q.empty()) {
		int h = q.front().first;
		int step = q.front().second;
		q.pop();
		for (int i = first[h]; i; i = edge1[h].next) {
			if (book[edge1[i].to] == 1)
				continue;
			if (edge1[i].to == t) {
				return step + edge1[i].w;
			}
			book[edge1[i].to] = 1;
			q.push(make_pair(edge1[i].to, step + edge1[i].w));
		}
	}
}

inline int find(int x) {
	if (fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

inline void merge(int x, int y) {
	fa[find(y)] = find(x);
}

inline void add(int x, int y, int w) {
	f++;
	edge1[f].to = y;
	edge1[f].w = w;
	edge1[f].next = first[x];
	first[x] = f;
}

signed main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> m >> n >> d >> p;
	for (int i = 1; i <= n + m; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++) {
		cin >> jinchu[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			edge[++cnt] = {i + n, a, t};
		}
	}
	stable_sort(edge + 1, edge + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (find(edge[i].u) != find(edge[i].v)) {
			merge(edge[i].u, edge[i].v);
			num++;
			sum += edge[i].w;
			add(edge[i].u, edge[i].v, edge[i].w);
			add(edge[i].v, edge[i].u, edge[i].w);
			if (num == n + m - 1)
				break;
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> x >> y;
		int ssum = bfs(x, y);
		cout << ssum + jinchu[x] + jinchu[y] << "\n";
		while (!q.empty())
			q.pop();
		memset(book, 0, sizeof(book));
	}

	return 0;
}
