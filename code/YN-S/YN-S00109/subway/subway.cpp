#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k[505], a[505][500005], t[505][500005], x, y, ans;

struct relation {
	int u, v;
	int num;
};
vector <relation> r;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int j = 1; j < k[i]; j++) {
			for (int o = j + 1; o <= k[i]; o++) {
				relation e, b;
				e.u = a[i][j], e.v = a[i][o];
				b.u = a[i][o], b.u = a[i][j];
				e.num = b.num = t[i][o] + t[i][j];
				r.push_back(e);
				r.push_back(b);
			}
		}
	}
	for (int l = 1; l <= q; l++) {
		cin >> x >> y;
		cout << w[x] + w[y] << endl;
	}
	return 0;
}
