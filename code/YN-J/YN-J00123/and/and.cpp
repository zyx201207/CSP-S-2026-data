#include <bits/stdc++.h>
using namespace std;
int a[1000005], n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (i = m - 1; i >= 1 ; i--) {
		a[i] = a[i] & a[i + 1];
	}
	cout << a[m];
	return 0;
}