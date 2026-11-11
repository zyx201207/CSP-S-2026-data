#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], maxn, cnt;

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		int x;
		cin >> x;
		a[i] = x;
	}

	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n - 1; j++) {

			int s = a[i];
			int sum = a[j + 1];
			maxn = max (s, sum);
			cnt++;

			if (cnt > m) {
				continue;
			}
		}
	}

	cout << maxn;
	return 0;
}