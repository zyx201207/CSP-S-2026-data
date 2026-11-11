#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
long long  d,  cnt = 0;
long long a[N];
long long minn = INT_MAX;
int ans = 0;

long long dfs(int m, long long dep,  long long cnts) {

	if (dep >= m) {
		return abs(cnts);
	}

	long long minns = INT_MAX;

	for (int i = 1; i <= d; i++) {

		minns = min(minns, dfs(m, dep + i,  cnts + 1));

		if (minns == minn)
			ans++;
	}

	minn = minns;

	if (ans == 2) {
		//ans = 0;
		return 1;
	}

	//ans = 0;
	return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;

	cin >> c >> t;
	int n;


	for (int u = 0; u < t; u++) {

		cin >> n >> d;

		for (int i = 0; i < n; i++) {

			cin >> a[i];
		}

		for (int i = n; i >= n - ((n  / d - 1 ) * d); i--) {

			cnt += dfs(i, 0, n - ((n / d - 1 ) * d));
			ans = 0;
		}

		cout << cnt << endl;
	}

	return 0;
}