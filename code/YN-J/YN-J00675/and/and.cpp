#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000001], mx = -1e9;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	cout << mx;
	return 0;
}