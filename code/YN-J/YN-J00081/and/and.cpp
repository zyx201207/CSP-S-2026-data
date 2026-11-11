#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int m, n, cnt, ans;

int cmp(int x, int y) {
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
	for (int i = 1; i < m; i++) {
		cnt = a[i + 1] & a[i];
		ans = cnt & a[i + 1];
	}
	cout << ans;
	return 0;
}