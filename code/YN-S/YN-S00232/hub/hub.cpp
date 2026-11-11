#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long c, t;
long long u[2000005], v[2000005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
	}
	return 0;
}