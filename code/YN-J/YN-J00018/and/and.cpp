#include <bits/stdc++.h>
using namespace std;

bool cmp(long long &x, long long &y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);
	long long ans = a[0];
	for (int i = 1; i < m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
