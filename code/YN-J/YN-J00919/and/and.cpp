#include <bits/stdc++.h>
using namespace std;
#define long long
#define endl '\n'
long long n, m;
long long a[1000000 + 1];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= m - 1; i++) {
		a[i] = 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	cout << a[1];
	return 0;
}