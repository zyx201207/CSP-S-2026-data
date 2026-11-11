#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 1 || m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		cout << a[n];
		return 0;
	}
	cout << 1;
	return 0;
}