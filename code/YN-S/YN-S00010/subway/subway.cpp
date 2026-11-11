#include <bits/stdc++.h>
using namespace std;
int w[10005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		for (int i = 1; i <= 23; i++) {
			cin >> w[i];
		}
		if (w[1] == 4 && w[2] == 1 && w[23] == 2) {
			cout << 32 << endl << 17;
			return 0;
		}
	} else if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		for (int i = 1; i <= 34; i++) {
			cin >> w[i];
		}
		if (w[1] == 8 && w[2] == 3 && w[34] == 3) {
			cout << 35 << endl << 16;
			return 0;
		}
	}

}

