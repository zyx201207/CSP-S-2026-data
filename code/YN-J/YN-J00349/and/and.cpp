#include <bits/stdc++.h>
using namespace std;
long long a[200005], ans;

bool flag(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, sum = -1;
	cin >> n >> m;
	int id = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, flag);
	ans = a[1];
	for (long long i = 2; i <= m; i++) {
		ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}