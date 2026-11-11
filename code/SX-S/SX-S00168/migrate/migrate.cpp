#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, next;
	long long w;
} eage[500005];
long long cnt = 0, head[500005], n, d, t, c, dis[5005], a[5005], kis[5005];
bool vis[5005];

void fun(int u, int v, long long w) {
	cnt++;
	eage[cnt].to = v;
	eage[cnt].w = w;
	eage[cnt].next = head[u];
	head[u] = cnt;
}

void dijk(int s) {
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		kis[i] = 0;
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
			if (dic + eage[i].w == dis[v]) {
				kis[v]++;
			}
			if (dic + eage[i].w < dis[v]) {
				dis[v] = dic + eage[i].w;
				kis[v] = 1;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cnt = 0;
		memset(head, -1, sizeof(head));
		cin >> n >> d;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) {
					fun(i, j, 1);
					fun(j, i, 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			dijk(i);
			for (int j = i + 1; j <= n; j++) {
				if (kis[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
