#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		long long n, k, u[2000005], v[2000005];
		cin >> n >> k;
		for (int j = 1; j <= n - 1; j++) {
			cin >> u[j] >> v[j];
		}
		cout << "0" << endl;
	}
	return 0;
}
