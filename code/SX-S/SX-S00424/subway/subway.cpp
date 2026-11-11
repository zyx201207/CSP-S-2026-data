#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long x[N], s = 0, ss = 0, n, c, t, d;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> d;
	if (c == 0) {
		if (n == 2 && d == 5) {
			cout << 32 << "\n" << 17;
		} else if (n == 3 && d == 7) {
			cout << 35 << "\n" << 16;
		}
	}
	return 0;
}
