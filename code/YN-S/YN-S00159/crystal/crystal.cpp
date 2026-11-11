#include <bits/stdc++.h>
#define maxn 500050
#define ll long long
using namespace std;
ll n, m, a[maxn], ky, ans, p, an, linm;
bool ab;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2)
			ky = a[i] - a[i - 1];
		if (i >= 3 && a[i] - a[i - 1] != ky)
			ab = 1;
	}
	if (ab == 0) {
		p = n - 1;
		while (m - (a[n] - a[p]) >= 0 && p >= 1) {
			m -= a[n] - a[p];
			ans++;
			p--;
		}
	} else {
		sort(a + 1, a + 1 + n);
		for (int i = n; i >= 2; i--) {
			p = i - 1;
			an = 0;
			linm = m;
			while (linm - (a[i] - a[p]) >= 0 && p >= 1) {
				linm -= a[i] - a[p];
				an++;
				p--;
			}
			ans = max(an, ans);
		}
	}
	cout << ans + 1;
	return 0;
}