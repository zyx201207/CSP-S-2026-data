#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, num;
	cin >> n >> m;
	int a[200005];

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	sort(a, a + n);
	num = a[n - 1];

	for (int i = n - 2; i >= n - m; i--) {

		num = num & a[i];
	}

	cout << num;
	return 0;
}