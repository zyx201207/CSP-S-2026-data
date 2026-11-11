#include <bits/stdc++.h>
using namespace std;
int c, t, cnt;
int a[510];
int vis[510];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int vis;
				if (abs(a[i] - a[j]) <= d) {


				}
			}
			for (int i = 2; i <= n; i++) {
				if (vis[i] == 2)
					cnt++;
			}
		}
		cout << cnt;
	}


	return 0;
}