#include <bits/stdc++.h>
using namespace std;

const long long N = 2e6 + 101;

long long c, t;
long long x[N];
long long n, d;

inline void work() {

	cin >> n >> d;
	memset(x, 0, sizeof 0);
	for (long long i = 1; i <= n; i++) cin >> x[i];
	
	if (c == 11 || c == 12) {
		long long del = x[2] - x[1];
		if (del > d) {
			cout << 0 << endl;
			return ;
		}
		long long len = d / del;
		if (len * 2 - 1 > n - 1 || len <= 1) cout << 0 << endl;
		else cout << n - 2 * len + 1 << endl;
	}
}

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t--) {
		work();
	}
	
	return 0;
}

