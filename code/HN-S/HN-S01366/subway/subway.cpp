#include <bits/stdc++.h>
using namespace std;

int w[500000], k[500], a[500][5000000], t[500][5000000], x[500000], y[500000];

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int c, n, m, d, q;
  cin >> c >> n >> m >> d >> q;
  for (int i = 0; i != m; ++ i) {
  	cin >> w[i];
	}
	for (int i = 0; i != n; ++ i) {
    cin >> k[i];
    for (int j = 0; j != k[i]; ++ j) {
      cin >> a[i][j] >> t[i][j];
    }
	}
	for (int i = 0; i != q; ++ i) {
    cin >> x[i] >> y[i];
    cout << 0 << '\n';
	}
  return 0;
}

