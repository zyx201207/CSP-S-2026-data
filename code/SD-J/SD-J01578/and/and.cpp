#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans = -1, p = 0;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
//	for (int i = 0; i < n; i ++) {
//		for (int j = 31; j >= 0; j --) {
//			cout << ((a[i] & (1 << j)) >> j);
//		}
//		cout << endl;
//	}
	sort(a, a + n, cmp);
//	for (int i = 0; i < n; i ++) {
//		cout << a[i] << ':';
//		for (int j = 31; j >= 0; j --) {
//			cout << ((a[i] & (1 << j)) >> j);
//		}
//		cout << endl;
//	}
//	cout << endl;
	do {
		ans = -1;
		for (int i = p; i < m + p; i ++) {
			ans &= a[i];
		}
		p ++;
	}
	while (ans == 0);
	cout << ans << '\n';
	return 0;
}
