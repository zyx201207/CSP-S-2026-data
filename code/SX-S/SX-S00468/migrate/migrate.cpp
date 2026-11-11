#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d, s = 0;
		cin >> n >> d;
		long long x[250000];
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n - 2; i++) {
			long long js = 0;
			for (int j = i + 3; j < n; j++) {
				for (int k = 0; k <= j - i - 2; k++) {
					if (x[i + k + 2] - x[i + k] <= 2 * d) {
						js++;
					}
				}
				if (js == 2) {
					s++;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
