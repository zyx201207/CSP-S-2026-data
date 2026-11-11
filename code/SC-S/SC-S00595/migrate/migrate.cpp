#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
int a[N];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 3; j <= n; j++) {
				if ((d * (j - i - 2) < (a[i + 3] - a[i])) && (d *(j - i - 1) > (a[i + 3] - a[i]))) {
					int num = 0;
					for (int k = i + 1; k <= j; k++) {
						if ((a[k] - a[i]) <= d && a[j] - a[k] <= d) {
							num++;
						}
					}
					if (num == 2) {
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}