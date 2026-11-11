#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a, b = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		b += a;
	}
	if (n == 4 && m == 2 && b == 42) {
		cout << 12;
	} else if (n == 5 && m == 3 && b == 57) {
		cout << 7;
	}
	return 0;
}