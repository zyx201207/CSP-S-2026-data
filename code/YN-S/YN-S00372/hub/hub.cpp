#include <bits/stdc++.h>
using  namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	int n, k;
	int x, y;
	int d = n;

	while (t) {
		cin >> n >> k;

		while (n - 1) {
			cin >> x >> y;
			n--;
		}

		t--;

		if ((d - 1) % 2 != 0)
			cout << 1;
		else
			cout << 2;
	}

	return 0;
}