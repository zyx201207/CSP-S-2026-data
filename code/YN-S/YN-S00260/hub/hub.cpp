#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int m, c, t, n, k;
	cin >> c >> t >> n >> k;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
		for (int j = 0; j < t; j++) {
			cin >> a[j];
			if (n == 2 * m + 1) {
				cout << a[i] - m << endl << a[i] + 1;
			}
		}
	}
	return 0;
}