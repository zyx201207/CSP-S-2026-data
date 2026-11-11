#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
int n;
int a[1000000 + 1];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n % 10 == n / 100 == n / 1000) {
		cout << 0;
	}
	return 0;
}