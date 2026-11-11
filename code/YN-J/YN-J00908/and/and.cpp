#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (ans == 0) {
			ans = a[i];
		} else {
			ans &= a[i];
		}
	}
	cout << ans;
	return 0;
}