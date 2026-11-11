#include <bits/stdc++.h>
using namespace std;
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, sum;
	long long maxx = 0;
	cin >> n >> m;
	cin >> a[0];

	for (int i = 1; i < n; i++) {

		cin >> a[i];
		sum = a[i] & a[i - 1];
	}

	for (int i = 1; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			maxx = max(maxx, a[i] & a[j]);
		}
	}

	if (m == 1) {
		sort(a, a + n);
		cout << a[n - 1];
	}

	if (m == n) {
		cout << sum;
	}

	if (m == 2) {
		cout << maxx;
	}

	return 0;
	fclose(stdin);
	fclose(stdout);
}