#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans;
int a[1000000 + 1];
char c[1000000 + 1];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int j = 1; j * 2 <= n; j++) {
		if (c[j] == c[n - j + 1]) {
			ans += a[j] - a[n - j + 1];
		} else
			ans += a[j];
	}
	cout << ans << endl;
	return 0;
}