#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long a[N], f[N], g[N];
long long b[2000005];
void solve() {
	long long n, d;
	cin >> n >> d;
	if(n > 5000) {
		for(int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		long long D = b[2] - b[1];
		if(D >= d) cout << 0 << endl;
		else {
			//cout << d / D << " ";
			cout << max(0ll, n - d / D * 2 + 1) << endl;
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = 0; g[i] = 1;
		for(int j = i + 1; j <= n; j++) {
			f[j] = n + 1; g[j] = 0;
			for(int k = j - 1; k >= i; k--) {
				if(a[j] - a[k] > d) break;
				f[j] = min(f[j], f[k] + 1);
			}
			for(int k = j - 1; k >= i; k--) {
				if(a[j] - a[k] > d) break;
				if(f[k] == f[j] - 1) g[j] += g[k];
			}
			//cout << f[j] << " " << g[j] << endl;
			if(g[j] == 2) ans++;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
