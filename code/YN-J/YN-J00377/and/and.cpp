#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int sum = a[1];
	for (int i = 2; i <= m; i++) {
		sum &= a[i];
	}
	cout << sum;
	return 0;
}