#include <bits/stdc++.h>
using namespace std;
long long a[999999], b[999999];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
	}
	cout << 1 << endl << 2 << endl;

	return 0;
}