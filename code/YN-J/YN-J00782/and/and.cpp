#include <bits/stdc++.h>
using namespace std;

bool cmp(long x, long y) {
	return x > y;
}

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[100005] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1];

	for (int i = 2; i <= m; i++) {
		if (ans &= a[i] == 0) {
			i++;
		}
		ans &= a[i];
	}
	cout << ans;
	return 0;
}