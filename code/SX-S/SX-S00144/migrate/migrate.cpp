#include <bits/stdc++.h>
using namespace std;
int arr[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		if (2 * (arr[2] - arr[1]) == d) {
			cout << n - 3 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
