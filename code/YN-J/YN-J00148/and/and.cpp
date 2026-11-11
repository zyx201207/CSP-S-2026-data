#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a[200002];
	int n, m, sum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	sum = a[n];
	for (int i = n; i >= n - m + 2; i--) {
		sum = sum & a[i - 1];
	}
	cout << sum;
	return 0;
}