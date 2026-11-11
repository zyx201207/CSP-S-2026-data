#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		long long ans = 0;
		long long a[n + 10];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		bool flag = true;
		long long cha = a[2] - a[1];
		for (int i = 2; i <= n; i++) {
			if (cha != (a[i] - a[i - 1]))
				flag = false;
		}
		if (flag) {
			for (int i = 1; i <= n; i++) {
				if (a[i] + 2 * d - 1 <= a[n])
					ans++;
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
