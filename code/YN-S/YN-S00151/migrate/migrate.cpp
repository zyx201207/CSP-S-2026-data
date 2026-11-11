#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int gunmu, T;
long long n, a[N];
long long d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> gunmu >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long cnt = 0;
		for (int i = 1; i <= n - 3; i++) {
			for (int k = i + 2; k <= n; k++) {
				int o = 0;
				for (int j = i + 1; j + 1 <= k; j++) {
					if (a[i] + d < a[k] && a[i] + d >= a[j] && a[j] + d >= a[k]) {
						o++;
					}
				}
				if (o == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}