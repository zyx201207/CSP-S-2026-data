#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("and.in", "w", stdin);
	freopen ("and.out", "r", stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	int ans = a[0];
	for (int i = 0; i < m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
