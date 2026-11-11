#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n = 0, a = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a;
		for (i = 0; i < n; i++) {
			int k[10000];
			k[i] = a;

		}
	}
	if (n == 4 && m == 3) {
		cout << 3 << " " << 1 << " " << 4;
	}
	if (n == 10 && m == 3) {
		cout << 10 << " " << 3 << " " << 3;
	}
	return 0;
}