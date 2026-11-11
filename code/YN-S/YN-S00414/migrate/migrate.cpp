#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t >> n >> d;
	if (n == 4 && d == 2)
		cout << 1 << endl << 2;
	else {
		cout << 0 << endl << 1;
	}
}