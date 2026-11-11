#include <bits/stdc++.h>
using namespace std;
long long a[1000][1000];
long long t[1000][1000];
int k[505];
int x[100005], y[100005], end[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> m >> d >> q;
	int w[m + 5];

	for (int i = 0; i < m; i++) {

		cin >> w[i];
	}

	for (int i = 0; i < n; i++) {

		cin >> k[i];

		for (int j = 0; j < k[i]; j++) {

			cin >> a[i][j] >> t[i][j];
		}
	}

	for (int i = 0; i < q; i++) {

		cin >> x[i] >> y[i];
	}

	return 0;
	fclose(stdin);
	fclose(stdout);
}