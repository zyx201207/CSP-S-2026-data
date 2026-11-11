#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int a, b, c[1000005];
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c[i];
		while (c[i] > 0) {
			c[i] %= 0;
			c[i] /= 0;
		}
	}
	return 0;
}
