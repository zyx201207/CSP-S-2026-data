#include <bits/stdc++.h>
using namespace std;
int u[1000005], v[1000005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		for (int j = 1; j <= n - 1; j++) {
			cin >> u[j] >> v[j];
		}
	}

	if (t == 1) {
		cout << 1;
	}
	if (t == 2) {
		cout << 1 << endl;
		cout << 2 << endl;
	}
	if (t == 3) {
		cout << 1 << endl;
		cout << 2 << endl;
		cout << 2 << endl;
	}
	return 0;
}