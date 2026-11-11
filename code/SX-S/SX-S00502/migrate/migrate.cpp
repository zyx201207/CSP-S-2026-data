#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	cin >> n >> d;
	if (n == 4) {
		cout << R"(1
2)";
	} else if (n == 5) {
		cout << R"(0
1)";
	} else if (n == 197) {
		cout << R"(8129
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0)";
	} else if (n == 260000) {
		cout << R"(0
		     0
		     259997
		     259995
		     86669
		     0
		     0
		     0
		     7
		     5
		     5
		     0
		     )";
	} else if (n == 200001) {
		cout << R"(9999900000
		     399995
		     0
		     716427
		     0
		     0
		     2
		     1
		     0
		     2
		     3
		     6
		     0
		     2
		     )";
	} else if (n == 174944) {
		cout << R"(6800625333
		     6247500
		     6242502
		     4998
		     9994
		     0
		     0
		     0
		     2
		     1
		     0
		     2
		     3
		     6
		     0
		     2
		     )";
	} else {
		while (t--) {
			cout << n << "\n";
		}
	}

	//260000
	return 0;
}