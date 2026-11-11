#include <bits/stdc++.h>
using namespace std;

long long c, t;
long long n, d;
long long zb[10000000];
long long ans[2000000];
bool what;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> zb[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int g = j; g <= n - j + 1; g++) {
				if (zb[j] + d == zb[g]) {
					ans[i]++;
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
