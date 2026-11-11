#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], n, m, maxx, b[N];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}