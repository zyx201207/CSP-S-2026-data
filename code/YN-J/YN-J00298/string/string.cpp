#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n, a[N], ans;
char c[N];

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1, j = n; i < j; ) {
		if (a[i] < a[j]) {
			if (c[i] != c[j]) {
				ans += a[i];
			}
			a[j] -= a[i], i++;
		} else if (a[i] > a[j]) {
			if (c[i] != c[j]) {
				ans += a[j];
			}
			a[i] -= a[j], j--;
		} else {
			if (c[i] != c[j]) {
				ans += a[i];
			}
			i++, j--;
		}
	}
	cout << ans << '\n';
	return 0;
}