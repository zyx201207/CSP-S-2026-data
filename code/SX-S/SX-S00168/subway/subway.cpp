#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, next;
	long long w;
} eage[500005];
long long W[500005], k[505], dis[500005], t[505][5005], f[2005][2005];
bool vis[5005];
int cnt = 0, head[500005], n, m, c, d, Q, a[505][20005];

void fun(int u, int v, long long w) {
	cnt++;
	eage[cnt].to = v;
	eage[cnt].w = w;
	eage[cnt].next = head[u];
	head[u] = cnt;
}

void dijk(int s) {
	for (int i = 1; i <= m; i++) {
		vis[i] = 0;
		dis[i] = 0x3f3f3f3f;
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		auto tt = q.top();
		q.pop();
		long long dic = tt.first;
		int num = tt.second;
		if (vis[num]) {
			continue;
		}
		vis[num] = 1;
		for (int i = head[num]; i != -1; i = eage[i].next) {
			int v = eage[i].to;
			if (dic + eage[i].w < dis[v]) {
				dis[v] = dic + eage[i].w;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(head, -1, sizeof(head));
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (j >= 2) {
				f[a[i][j - 1]][a[i][j]] = t[i][j - 1];
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k[i - 1]; j++) {
			for (int p = 1; p <= k[i]; p++) {
				if (a[i - 1][j] == a[i][p]) {
					for (int pp = p + 1; pp <= k[i]; pp++) {
						f[a[i - 1][j]][a[i][pp]] = t[i - 1][j] + t[i][pp];
						fun(a[i - 1][j], a[i][pp], t[i - 1][j] + t[i][pp]);
					}

				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (f[i][j] != 0) {
				fun(i, j, f[i][j]);
			}
		}
	}
	int xl, xr;
	while (Q--) {
		cin >> xl >> xr;
		dijk(xl);
		long long ans = dis[xr] + W[xl] + W[xr];
		cout << ans << endl;
	}
	return 0;
}
