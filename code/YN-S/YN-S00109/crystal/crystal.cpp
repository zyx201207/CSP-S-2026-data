#include <bits/stdc++.h>
using namespace std;
int n, a[500005], m, ans, l, r;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l = 1;
	int ned = 0;
	ans = 1;
	for (int r = 2; r <= n; r++) {
		ned += (a[r] - a[r - 1]) * (r - l);
		while (ned > m) {
			ned -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}
