#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200010];
int maxx = LLONG_MIN;
bool flag = 1;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i - a[i] != 1) flag = 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	if (m == 1) cout << a[1];
	else if (m == n) {
		int x = a[1];
		for (int i = 1; i <= n; i++) x = x & a[i];
		cout << x;
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) maxx = max(maxx, a[i] & a[j]);
		cout << maxx;
	}
	else if (flag) cout << n - m;
	else cout << a[n - m + 1];
	return 0;
}
