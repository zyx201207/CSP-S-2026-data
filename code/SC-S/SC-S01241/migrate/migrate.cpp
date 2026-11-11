#include<bits/stdc++.h>
using namespace std;
const int N = 3 + 2e5;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n;
		long long d, ans = 0, a[N];
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i - 2; j++) {
				long long qwe = a[i] - a[j];
				if (qwe == 2 * d - 1) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}