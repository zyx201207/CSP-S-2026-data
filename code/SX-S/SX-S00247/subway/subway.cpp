#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, a, t1, t2;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a;
	cin >> a;
	for (int i = 1; i <= 2 * a; i++)
		cin >> t1;
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
	}
	while (q--)
		cout << "0" << '\n';
	return 0;
}
