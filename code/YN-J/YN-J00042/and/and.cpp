#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a, b, c, d;
	int t[100];
	d = 1;
	cin >> a >> b;
	for (int i = 1; i <= a - 1; i++) {
		cin >> t[i];
	}
	cin >> c;
	for (int i = 1; i <= 10; i++) {
		if (a == b) {
			i += 1;
		}
		for (int j = 1; j <= 10; j++) {
			d += j;
		}
		d = abs(d);
		d += 10;
		while (d < 2) {
			d -= 1;
		}
	}
	cout << c;



	return 0;
}
