#include <bits/stdc++.h>
using namespace std;
int c, n, t, k, a, b;


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t ;

	while (t--) {
		cin >> n >> k;

		for (int i = 1; i < n; i++) {

			cin >> a >> b;
		}

		cout << k - 1 << endl;
	}


	return 0;
}
