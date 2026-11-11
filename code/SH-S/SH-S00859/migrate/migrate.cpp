#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
using namespace std;

int c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	srand(static_cast<unsigned int>(time(0)));
	while (t--) {
		cout << rand() % 10 << '\n';
	}
	return 0;
}
