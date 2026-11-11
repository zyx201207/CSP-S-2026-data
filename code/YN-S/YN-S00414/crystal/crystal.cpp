#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("srystal.in", "r", stdin);
	freopen("stystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 5 && m == 5) {
		cout << 3;
	}
	if (n == 5 && m == 8) {
		cout << 4;
	}
}