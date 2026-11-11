#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, T;
int a[500010];

struct acb {
	int x, y, z;
};
vector<acb>b[500010];
int c[500010];
int d[500010];
int aa[500010];

void di() {
	int x, y;
	cin >> x >> y;
	memset(aa, 0x3f, sizeof(aa));
	aa[x] = a[x];
	priority_queue<pair<int, int>>q;
	q.push({0, x});
	while (q.size()) {
		int i = q.top().second;
		q.pop();
		for (int j = 0; j < b[i].size(); j++) {
			if (aa[b[i][j].x] > aa[i] + b[i][j].y + b[i][j].z) {
				aa[b[i][j].x] = aa[i] + b[i][j].y + b[i][j].z;
				q.push({-aa[b[i][j].x], b[i][j].x});
			}
		}
	}
	cout << aa[y] + a[y] << endl;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> T >> T;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int nm;
		cin >> nm;
		for (int i = 1; i <= nm; i++)
			cin >> c[i] >> d[i];
		for (int i = 1; i <= nm; i++) {
			for (int j = 1; j <= nm; j++) {
				if (i == j)
					continue;
				b[c[i]].push_back({c[j], d[j], d[i]});
			}
		}
	}
	while (T--) {
		di();
	}
	return 0;
}
