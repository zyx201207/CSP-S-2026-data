#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c, tt;
	cin >> c >> tt;
	while (tt--) {
		int n, d;
		cin >> n >> d;
		vector<int> x(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		long long ans = 0;
		for (int l = 1; l <= n; ++l) {
			for (int r = l + 1; r <= n; ++r) {
				if (x[r] - x[l] > d) {
					int cnt = 0;
					for (int p = l + 1; p < r; ++p) {
						if ((x[p] - x[l] <= d) && (x[r] - x[p] <= d)) {
							++cnt;
						}
						if (cnt >= 3) break;
					}
					if (cnt == 2) ++ans;
					if (cnt == 1) 
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}