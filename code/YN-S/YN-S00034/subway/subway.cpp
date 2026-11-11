#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;

struct node {
	long long w, t;
} arr[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;

	for (long long i = 1; i <= m; i++) {

		cin >> arr[i].w;
	}

	for (long long i = 1; i <= n; i++) {

		long long k;
		cin >> k;

		for (long long j = 1; j <= k; j++) {

			long long a, t;
			cin >> a >> t;
			arr[a].t = t;
		}
	}

	for (long long i = 1; i <= q; i++) {

		long long x, y;
		cin >> x >> y;
		cout << arr[x].w + arr[x].t + arr[y].w + arr[y].t << endl;
	}

	return 0;
}