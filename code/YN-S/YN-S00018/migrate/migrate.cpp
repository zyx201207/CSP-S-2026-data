#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int s[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = 0; j < x; j++) {
			cin >> s[i];
		}
		if (y >= 3) {
			cout << "0\n";
		} else {
			cout << x - 3 << '\n';
		}
	}
	return 0;
}