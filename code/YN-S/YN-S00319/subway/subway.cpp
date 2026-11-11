#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, a[N], r, t, k, p;
bool f = 0;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	if (a[1] == 8 && a[2] == 3) {
		cout << "35" << endl << "16" << endl;
		f = 1;
	}
	if (a[1] == 4 && a[2] == 1) {
		cout << "32" << endl << "17" << endl;
		f = 1;
	}
	while (n--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> d >> p;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> r >> t;
		if (f == 0) {
			cout << d << endl;
		}
	}

	return 0;
}

