#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[200001];
long long sum, ans;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {

		for (int j = 1; j <= n; j++) {

			for (int k = j; k <= n; k++) {

				ans = max(sum, a[j] & a[k]);
			}
		}
	}

	cout << ans;
	return 0;
}

