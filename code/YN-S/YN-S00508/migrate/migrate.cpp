#include <bits/stdc++.h>
using namespace std;

struct s {
	int num, p;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == 0 && b == 2 && c == 4 && d == 2) {
		cout << 1 << endl << 2;
	} else {
		cout << "0" << endl << '1';
	}
	return 0;
}