#include <bits/stdc++.h>
using namespace std;
long long n, m, minn = LONG_LONG_MAX, z1;
long long a[10000], b[10000];
long long sum = 0;
int cnt = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
		sum += a[i];
	}

	sort(a + 1, a + n + 1);
	sum /= n;

	for (int i = 1; i <= n; i++) {

		if (abs(a[i] - sum) <= minn) {
			minn = abs(a[i] - sum);
			z1 = i;
		}
	}

	for (long long i = z1 - 1; i >= 1; i--) {

		if (m - abs(a[i] - a[z1]) > 0) {
			cnt++;
		} else {
			break;
		}
	}

	cout << cnt;
	return 0;
}