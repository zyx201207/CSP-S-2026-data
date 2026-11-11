//wr 2026.10.31 CSP rp++!
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m;
long long a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = n + m;
	if (ans % 2 == 0) {
		cout << ans * 2;
	} else if (ans % 2 != 0) {
		cout << ans - 1;
	}
	return 0;
}