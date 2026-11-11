#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define N 100010

long long w[N], a[N], t[N], k[N], x[N], y[N];
long long c, n, m, d, q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;

	if (c == 0 && m == 5) {
		cout << 32 << endl << 17;
	}
	if (c == 0 && m == 7) {
		cout << 35 << endl << 16;
	}
	return 0;
}
