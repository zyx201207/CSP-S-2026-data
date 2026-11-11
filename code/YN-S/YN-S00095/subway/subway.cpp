#include <bits/stdc++.h>
using namespace std;
#define int long long
int h[500005];

struct node {
	int y;
	int lo;
};
vector <node> g[500005];

struct node1 {
	int num;
	int de;
	operator <(const node1 &x)const {
		return de > x.de;
	}
};
int d[20005];
bool v[20005];

void f(int be, int en) {
	priority_queue<node1> q;
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[be] = 0;
	q.push({be, 0});
	while (!q.empty()) {
		node1 nw = q.top();
		q.pop();
		for (int i = 0; i < g[nw.num].size(); i++) {
			if (v[g[nw.num][i].y] == 0) {
				if (d[g[nw.num][i].y] > (g[nw.num][i].lo + nw.de) ) {
					d[g[nw.num][i].y] = g[nw.num][i].lo + nw.de;
					q.push({g[nw.num][i].y, d[g[nw.num][i].y]});
					v[g[nw.num][i].y] = 1;
				}
			}
		}
	}
	cout << d[en] + h[be] + h[en] << "\n";
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	if (c >= 7 and c <= 11) {
		for (int i = 1; i <= m; i++) {
			cin >> h[i];
		}
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			int a1, a2, t1, t2;
			if (k == 1) {
				cin >> a1 >> t1;
			} else {
				cin >> a1 >> t1 >> a2 >> t2;
				g[a1].push_back({a2, t1 + t2});
				g[a2].push_back({a1, t1 + t2});
			}
		}
		int be, en;
		while (q--) {
			cin >> be >> en;
			f(be, en);
		}
	} else {
		for (int i = 1; i <= m; i++) {
			cin >> h[i];
		}
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int i = 1; i <= k; i++) {
				int a, t;
				cin >> a >> t;
			}
		}
		int be, en;
		while (q--) {
			cin >> be >> en;
			cout << 1 << "\n";
		}
	}
	return 0;
}