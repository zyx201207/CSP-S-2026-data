#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	sort(a, a + n);
	int maxn = 0;

	if (m == 1) {
		cout << a[n - 1];
	} else {
		if (n % 2 == 0) {
			cout << a[n / 2];
		} else {
			cout << floor(a[n / 2]);
		}
	}

	return 0;
}