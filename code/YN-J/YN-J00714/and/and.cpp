#include <bits\stdc++.h>
using namespace std;
int a[100001], m, n, s[10001], maxx = -999999999;

int  main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		s[i] = a[i] && m;
		maxx = max(s[i], s[i + 1]);
	}
	cout << maxx;
	return 0;
}