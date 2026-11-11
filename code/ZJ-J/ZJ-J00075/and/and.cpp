#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int yu;
int ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int maxa;
		for (int i = 1; i < n; i++) {
			maxa = max(a[i], a[i + 1]);
		}
		cout << maxa;
		return 0;
	}
	yu = a[1];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			yu = max(yu, a[i] & a[j]);
		}
		ans = max(ans, yu);
		yu = 0;
	}
	cout << ans;
	return 0;
}
