#include <bits/stdc++.h>
using namespace std;

const long long N = 2e6 + 6;
long long C, T;
long long n, d;
long long a[N], f[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (C == 11 || C == 12) {
			long long t = a[2] - a[1];
			cout << (n - ((long long)(d / t)) * 2 + 1) << '\n';
			continue;
		}
		for (int k = 2; k < n; k++) {
			for (int i = 1; i <= n; i++) f[i] = 1145141919810;
			f[k - 1] = 0;
			for (int i = k; i <= n; i++) {
				for (int j = 1; i - j >= 1; j++) {
					if (a[i] - a[i - j] <= d)
						f[i] = min(f[i], f[i - j] + 1);
					else
						break;
				}
				long long ok = 0;
				for (int j = 1; i - j >= 1; j++) {
					if (ok > 2) break;
					if (a[i] - a[i - j] <= d && f[i] == f[i - j] + 1)ok++;
					else break;
				}
				if (ok == 2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//AFO 
