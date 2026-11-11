#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;

void solve() {
	srand(time(0));

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= q; i++) {
		cout << rand() << " ";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}