#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 505;

struct node {
	int stat, tim;
};

struct nodep {
	long long dis;
	int id;
	friend bool operator<(nodep x, nodep y) {
		return x.dis > y.dis;
	}
};

int c, n, m, d, p, st, en;
vector<node>g[N];
int w[N];
long long dis[N];
priority_queue <nodep> q;

void opt() {
	q.push({0, st});
	while (!q.empty()) {
		nodep v = q.top();
		q.pop();
		long long l = v.dis;
		int id = v.id;
		if (l > dis[id])
			continue;
		for (auto it : g[id]) {
			int nid = it.stat, tim = it.tim;
			if (dis[nid] > l + tim) {
				dis[nid] = l + tim;
				q.push({dis[nid], nid});
			}
		}
	}
	return;
}

int main() {
	int a, b, l;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in ", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> l;
		for (int j = 1; j <= l; j++) {
			cin >> a >> b;
			g[i + m].push_back({a, b});
			g[a].push_back({i + m, b});
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> st >> en;
		for (int i = 1; i <= n + m; i++) {
			dis[i] = LLONG_MAX;
		}
		dis[st] = 0;
		opt();
		cout << dis[en] + w[st] + w[en] << '\n';
	}

	return 0;
}
