#include <bits/stdc++.h>
using namespace std;
int a[500010];

struct node {
	int s, t;
};
node k[500010][500010];

struct nd {
	int sx, sy;
};
nd l[100010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j].s >> a[i][j].t;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sx >> a[i].sy;
	}
}