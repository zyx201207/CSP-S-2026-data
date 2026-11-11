#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int a[MAXN];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		for (int i = 1; i <= n; i++) {
			ans += a[i] ^ a[i + 1];
		}
	}
	cout << ans;
	return 0;
}