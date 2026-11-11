#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
int x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		ll idx = 1, ans = 1;
		if (n >= 1 && n <= 3) cout << "0\n";
		else {
			for (int i = 5; i <= n; i++) {
				if (i % 2 == 1) {
					ans += idx;
				} else {
					idx++;
					ans += idx;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
