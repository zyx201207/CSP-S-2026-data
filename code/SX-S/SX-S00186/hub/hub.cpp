#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int b, t;
	cin >> b >> t;
	int a[t + 3];
	for (int i = 1; i <= t; i++) {
		while (a[i] > 10 || a[i] < -10) {
			a[i ] /= 10;


		}
		if (a[i] < 0)
			a[i] *= -1;
		cout << a[i] << endl;
	}

	return 0;
}
