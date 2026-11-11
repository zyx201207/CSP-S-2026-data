#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d;
const int N = 2e6 + 10;
long long a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		bool b[N] = {0};
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[a[i]] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int ans = 0;
			for (int j = max(1, i - d); j < i; j++)
				if (b[j])
					ans++;
			if (ans >= 2) {
				cnt++;
			}
		}
		cout << cnt - 1 << " \n";
	}
	return 0;
}