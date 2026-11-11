#include <bits/stdc++.h>
using namespace std;

int c, t;
long long n, d, cnt, s;
long long a[2000100], b[2000100], dp[5000][5000];

void dfs(int x, int y, long long sp) {
	//cout << x << ' ' << y << endl;
	if (x == y) {
		b[sp]++;
		cnt = cnt == 0 ? sp : min(cnt, sp);
	}
	for (int i = x + 1; i <= n; i++) {
		if (a[i] - a[x] <= d) {
			dfs(i, y, sp + 1);
		} else
			break;
	}
}

int js(int x, int y) {
	return (a[y] - a[x] - 1) / d + 1;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c <= 2) {
		while (t--) {
			cin >> n >> d;
			s = 0;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			for (int i = 1; i <= n - 3; i++) {
				for (int j = i + 3; j <= n; j++) {
					cnt = 0;
					memset(b, 0, sizeof(b));
					dfs(i, j, 0);
					if (b[cnt] == 2) {
						s++;
					}
				}
			}
			cout << s << endl;
		}
	} else if (c == 13 || c == 14) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			cout << 0 << endl;
		}
	} else {
		while (t--) {
			cin >> n >> d;
			s = 0;
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			for (int i = 1; i <= n - 3; i++) {
				for (int j = i + 3; j <= n; j++) {
					int t = js(i, j);
					if (t == j - i - 1) {
						s++;
						//cout << t << ' ' << i << ' ' << j << endl;
					}

				}
			}
			cout << s << endl;
		}
		//}

		return 0;
	}
}