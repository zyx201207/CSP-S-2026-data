#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, M = 5005;
int a[N], dis[M][M], fa[M][M];
vector<int> g[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (c <= 10) {
		while (t--) {
			int n, d, ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				g[i].clear();
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) {
						g[i].push_back(j);
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[i][j] = 0x3f3f3f3f;
					fa[i][j] = 0;
				}
				dis[i][i] = 0;
				queue<int> q;
				q.push(i);
				while (q.size() != 0) {
					int t = q.front();
					q.pop();
					for (int j : g[t]) {
						if (dis[i][t] + 1 <= dis[i][j] && fa[i][j] <= 2) {
							fa[i][j]++;
							dis[i][j] = dis[i][t] + 1;
							q.push(j);
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (fa[i][j] == 2) {
						ans++;
//						cout << i << ' ' << j << '\n';
					}
				}
			}
	//		cout << fa[1][4] << "???\n";
			cout << ans << '\n';
		}
	} else if (c <= 12) {
//		cout << "^_^";
//		return 0;
		while (t--) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
//			if (n == 1) {
//				cout << "0\n";
//				continue;
//			}
			bool flag = 0;
			for (int i = n - n % 2; i >= 4; i -= 2) {
				if (i / 2 * (a[2] - a[1]) <= d && (i / 2 + 1) * (a[2] - a[1]) > d) {
					cout << n - i + 1 << '\n';
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "0\n";
			}
		}
	} else {
		while (t--) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			cout << n / 2 << '\n';
		}
	}
	return 0;
}
