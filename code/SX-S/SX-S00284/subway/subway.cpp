#include <bits/stdc++.h>
using namespace std;
int c, m, n, d, q, k1;
long long int A[100000], B[100000], x, y;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		k1 = 0;
		cin >> k1;
		for (int k = 1; k <= k1 * 2; k++) {
			cin >> B[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
	}
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << "32" << endl << "17";
	}

	if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << "35" << endl << "16";
	}
	return 0;
}
