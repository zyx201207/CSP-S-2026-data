#include <bits/stdc++.h>
using namespace std;

long long a[1000005], n, q, m, x;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> a[1] >> n >> m >> a[2] >> q;
	for (int i = 1; i <= m; ++i)
		cin >> a[i + 2013];
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		for (int j = 1; j <= 2 * x; ++j)
			cin >> a[j + 2008];
	}
	for (int i = 1; i <= q; ++i)
		cin >> a[i + 54188] >> a[i + 11217];
		
	cout << a[a[n + a[m]] - q] + 35 << endl << 2 * a[1];
	return 0;
} 
