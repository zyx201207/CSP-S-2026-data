#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
long long n, a[maxn], m;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = a[1];
	sort(a + 1, a + n + 1, cmp);
	for (long long i = 2; i <= m; i++) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}