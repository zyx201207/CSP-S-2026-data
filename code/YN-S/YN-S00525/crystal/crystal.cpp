#include <bits/stdc++.h>
using namespace std;

long long n, m, l = 1, r = 1, ans;
long long a[500010], b[500010], f[500010];



int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (r = 1; r <= n; r++) {
		f[r] = f[r - 1] + (a[r] - a[r - 1]) * (r - l);
		while (f[r] > m) {
			f[r] -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}