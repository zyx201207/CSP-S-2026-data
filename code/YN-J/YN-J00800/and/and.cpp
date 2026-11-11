#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, mx = INT_MIN;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	mx = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int sum = (a[i] & a[j]);
			mx = max(mx, sum);
		}
	}
	cout << mx;
	return 0;
}