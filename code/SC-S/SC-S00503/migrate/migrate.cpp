#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, t;
	cin >> c >> t;
	while (t--){
		int n;
		ll d;
		cin >> n >> d;
		vector<ll> x(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		ll ans = 0;
		for (int i = 1; i + 3 <= n; i++){
			int t = 0, t1;
			bool flag = 0;
			for (int j = i + 1; j <= n; j++){
				if (x[j] - x[j - 1] > d || j == n){
					if (t)
						ans += j - t1 - (j != n);
					break;
				}
				if (flag && j < n && x[j] - x[j - 2] <= d && x[j + 1] - x[j] <= d){
					if (++t == 2){
						ans += j - t1;
						break;
					}
					t1 = j;
				}
				if (j > 1 && j < n - 1 && x[j] - x[j - 1] <= d && x[j + 2] - x[j] <= d && x[j + 2] - x[j - 1] > d) flag = 1;
				else flag = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}