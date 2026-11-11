#include <bits/stdc++.h>
using namespace std;
int c, m, a[1000000], n, ans[1000000], l, some;

int niao(int p, int o) {
	int s = 0, sn = 0;

	while (s + p <= n) {
		s += p;
		ans[l] = p;
		sn++;
		l++;
	}

	if (s != n) {
		niao(p - o, 1);
	} else {
		return sn;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> m;

	while (m--) {
		int s;
		cin >> n >> s;

		for (int i = 0; i <= n; i++) {

			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {

			if (niao(m, 1) == niao(m, 2)) {
				some++;
			}
		}

		cout << some;
	}
	return 0;
}
