#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int taskid, T, n, d, res;
int f[N], g[N];
int x[N];

inline int read() {
	int f = 1, r = 0;
	char c;
	c = getchar();
	while (c < '0' || c > '9')
		f = -1, c = getchar();
	while (c >= '0' && c <= '9')
		r = r * 10 + c - '0', c = getchar();
	return f * r;
}
vector<int>e[N];

void update(int x, int c) {
	if (f[x] > c)
		f[x] = c, g[x] = 1;
	else if (f[x] == c)
		g[x]++;
}

void bfs(int s) {
	queue<int>q;
	q.push(s);
	memset(f, 0x3f, sizeof(f));
	memset(g, 0, sizeof(g));
	f[s] = 0, g[s] = 1;
	while (!q.empty()) {
		int u = q.front(), c = f[u];
		q.pop();
//		cout << u << ": ";
		for (auto v : e[u]) {
//			cout << v << ' ';
			if (f[v] >= c + 1)
				q.push(v);
			update(v, c + 1);
		}
//		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		res += (g[i] == 2);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	taskid = read(), T = read();
	while (T--) {
		n = read(), d = read();
		for (int i = 1; i <= n; i++) {
			x[i] = read();
		}
		for (int i = 1; i <= n; i++) {
			int idx = i - 1;
			while (x[i] - x[idx] <= d && idx > 0)
				e[i].push_back(idx), idx--;
			idx = i + 1;
			while (x[idx] - x[i] <= d && idx <= n)
				e[i].push_back(idx), idx++;
		}
		res = 0;
		for (int i = 1; i <= n; i++)
			bfs(i);
		cout << res / 2 << '\n';
		for (int i = 1; i <= n; i++)
			e[i].clear();
	}
	return 0;
}