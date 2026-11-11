#include <bits/stdc++.h>
using namespace std;
long long n, m, a;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	while (n--; m--;) {
		cout << n << m;
		cin >> a;
		for (int i = 0; i <= m; i++) {
			long long x = a + 1;
			cout  << x;
		}
	}


	return 0;
}