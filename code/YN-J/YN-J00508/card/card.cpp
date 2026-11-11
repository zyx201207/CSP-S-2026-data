#include <bits/stdc++.h>
using namespace std;
long long m, n;
const long long N = 5e5 + 10;
const long long M = 3e5 + 10;
long long o[N];
long long f[N];
long long d[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> o[i];

	}
	if (m == n) {
		for (long long i = 1; i <= n; i++) {
			cout << i << " ";
		}
	}

	return 0;
}
