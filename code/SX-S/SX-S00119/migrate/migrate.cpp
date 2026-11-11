#include <bits/stdc++.h>
using namespace std;
set<int> a;
int c, t, n, d, x;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	for (scanf("%d%d", &c, &t); t--;) {
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			a.insert(x);
		}
		for (auto i : a) {
			for (auto j = a.upper_bound(i + d); j != a.end(); j++)
				for (auto k = next(j); k != a.end(); k++) {
					if (*k - *j > d)
						break;

				}
		}
	}
}