#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	if (a > b) {
		return 1;
	}
	return 0;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	int x = a[0];;
	for (int i = 0; i < m; i++) {
		x = a[i] & x;
	}
	cout << x;
	return 0;
}