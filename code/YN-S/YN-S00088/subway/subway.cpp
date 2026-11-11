#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int l = 1;
		for (int h = 1; h <= l; h++) {
			l *= 2;
		}
		cout << l / 2;
	}
	return 0;
}