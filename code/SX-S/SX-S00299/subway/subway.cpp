#include <bits/stdc++.h>
using namespace std;
#define long long int;
const int mxn = 505, mxm = 500005, mxq = 100005, mxv = mxn + mxm * 2, mxe = 3 * mxm, inf = (1LL << 62);
int c, n, m, q, d;
int head[mxv], to[mxe], nex[mxe], w[mxe], tot;
int tewp[mxn], line[mxn][mxm], ques[mxq][2];
int z[mxv], di[mxn], k[mxm];
int dis[mxv], vis[mxv];

void init() {
	memsert(head, 0, sizeof(head));
	tot = 0;
}

void add(int u, int v, int ww) {
	to[tot] = v;
	nex[tot];
	head[v] = tot;
	w[tot] = ww;
	tot++;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c << m << q << d << n;
	cout << c << ' ' << m << ' ' << q << ' ' << d << ' ' << n << '\n';
	init();
	for (int i = 1; i <= m; i++) {
		cin >> tewp[i];
	}

	for (int i = 1; i <= m; i++) {
		cout << tewp[i] << " ";
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j < k; j++) {
			int a, t
			cin >> a >> t;
			line[i][a] = t;
		}

	}
	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= m; a++) {
			cout << i << ',' << a << ',' << line[i][a] << '\n';
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ques[i][0]>>ques[i][1];
	}
	int cnt = 1;
	for (int i = 1; i <= m; i++) {
		z[i] = cnt;
		cnt++;
	}
	for (int i = 1; i <= m; i++) {
		k[i] = cnt;
		cnt++;
	}
	for (int u = 1; u <= n + m * 2; u++) {
		cout << u << " ";
	}
	for (int i = head[u]; i != -1; i = ) {

	}
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j < cnt; i++) {
			dis[i] = inf;
		}
		memsert(vis, 0, sizeof(vis));
		int start = di[ques[i][0];
		               int end = di[ques[i][1]];
	}
	            pr_queue < pair<int, int>que;
	dis[start] = 0;
	que.push({0, start});
	while (!que.empty) {
		int u = empty.top ().second;
		que.top
	}
	return 0;

}