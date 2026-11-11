#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[100005], a[505][100005], t[505][100005], k[505];
int x, y, ans = INT_MAX;
int tong[200005];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			tong[a[i][j]] = j;
		}
	}
	while (q--) {
		cin >> x >> y;
		int l, r;
		for (int i = 1; i <= m; i++) {
			if (a[1][i] == x)
				l = i;
			if (a[1][i] == y)
				r = i;
		}
		cout << w[x] + w[y] + t[1][l] + t[1][r] << endl;
	}
	return 0;
}