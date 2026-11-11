#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[100005], b[100005];
int mx = -1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++) {
			mx = max(b[j], mx);
		}
	}
	cout << mx - 1;
	return 0;
}
