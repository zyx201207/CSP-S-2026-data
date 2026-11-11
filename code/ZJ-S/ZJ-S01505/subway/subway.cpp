#include <bits/stdc++.h>
using namespace std;
const int N = 500010, M = 510;
const long long inf = 1e18;
vector <pair <int, long long> > v[N]; 
long long w[N], f[M][M];
int c, n, m, d, q;
//int read() {
//	int f = 1;
//	char ch = getchar();
//	while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
//	if (ch == '-') {
//		f = -1;
//		ch = getchar();
//	}
//	int cnt = 0;
//	while (ch >= '0' && ch <= '9') {
//		cnt = cnt * 10 + ch - '0';
//		ch = getchar();
////		cout << ch << '\n';
//	}
////	exit(0);
//	return cnt * f;
//}
void Floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (f[i][k] + f[k][j] < f[i][j]) {
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	c = read(); n = read(); m = read();
//	d = read(); q = read();
//	cout << c << '\n';
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
//		w[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int A, T; cin >> A >> T;
			v[A].push_back({i, T});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			f[i][j] = f[j][i] = inf;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int) v[i].size(); j++) {
			for (int k = 0; k < (int) v[i].size(); k++) {
				int x = v[i][j].first, y = v[i][k].first;
				if (j == k) {
					f[x][y] = f[y][x] = 0;
					continue;
				}
				f[x][y] = min(f[x][y], v[i][j].second + v[i][k].second);
				f[y][x] = f[x][y];
			}
		}
	}
	Floyd();
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << f[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while (q--) {
//		int l = read(), r = read();
		int l, r; cin >> l >> r;
//		cout << l << ' ' << r << '\n';
		long long ans = inf;
		for (int i = 0; i < (int)v[l].size(); i++) {
			for (int j = 0; j < (int) v[r].size(); j++) {
				int x = v[l][i].first, y = v[r][j].first;
				ans = min(ans, f[x][y] + v[l][i].second + v[r][j].second);
			}
		}
//		printf("%lld\n", w[l] + w[r] + ans);
		cout << w[l] + w[r] + ans << '\n';
	}
	return 0;
}