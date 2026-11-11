#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200005], ans = -1, sl[200005], sr[200005];
bool vis[200005];
void dfs (long long cas, long long t) {
	if (t == m) {
		ans = max (ans, cas);
		return;
	}
	for (int i = 1; i <= n; i++) {
		long long c = cas & a[i], k = t + 1;
		if (vis[i]) continue;
		vis[i] = true;
		dfs (c, k);
		vis[i] = false;
	}
}

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) {
		for (int i = 1; i <= n; i++) {
			long long t = 1, cas = a[i];
			vis[i] = true;
			dfs (cas, t);
			vis[i] = false;
		}
		cout << ans << "\n";
	}
	else {
		if (m == 1) {
			sort (a + 1, a + n + 1);
			cout << a[n] << "\n";
		}
		else if (m == n) {
			long long s = a[1];
			for (int i = 2; i <= n; i++) s &= a[i];
			cout << s << "\n";
		}
		else if (m == 2) {
			long long x = -1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					x = max (x, a[i] & a[j]);
				}
			}
			cout << x << "\n";
		}
		else {
			sl[1] = a[1];
			sr[1] = a[n];
			for (int i = 2; i <= n; i++) sl[i] = sl[i - 1] & a[i];
			for (int i = n - 1; i >= 1; i--) sr[i] = sr[i + 1] & a[i];
			long long f = max (sl[n - 1], sr[2]);
			for (int i = 2; i < n; i++) f = max (f, sl[i - 1] & sr[n - i + 1]);
			cout << f << "\n";
		}
	}
	return 0;
}
