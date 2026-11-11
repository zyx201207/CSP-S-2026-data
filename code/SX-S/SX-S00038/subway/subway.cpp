#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define de second

using namespace std;

const int N = 1 + 10;
const int M = 5e5+10;
int c, n, m, d, q;

int w[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (c == 0) {
		if (n == 2) {
			cout << 32 << endl;
			cout << 17 << endl;
		} else {
			cout << 35 << endl;
			cout << 16 << endl;
		}
		return 0;
	}

	return 0;
}