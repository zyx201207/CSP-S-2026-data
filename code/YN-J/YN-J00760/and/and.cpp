#include <bits/stdc++.h>
using namespace std;
long long n, m, sum;
long long a[200005];
long long b[200005];
long long u[200005];

void dfs(long long ans, long long pos) {

	if (ans == m) {
		long long k = b[1];

		for (long long i = 0; i < m; i++) {


			k = k & b[i];
		}



		sum = max(k, sum);
	}

	for (long long i = pos; i <= n; i++) {

		if (u[i] == 0) {
			b[ans] = a[i];
			u[i] = 1;
			dfs(ans + 1, i);
			u[i] = 0;
		}
	}
}

int   main() {
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	dfs(0, 1);
	cout << sum;
	return 0;
}