#include <bits/stdc++.h>
using namespace std;
const int Max_i = 5e5 + 10;
long long a[Max_i];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int k;
	long long cnt = a[2] - a[1];
	int x = 1;

	for (int i = 3; i <= n && x < i; i++) {

		k = max(i - x, k) ;

		cnt += (i - x) * (a[i] - a[i - 1]);

		while (cnt > m && x < i) {
			cnt -= a[i] - a[x];
			x++;
		}

	}

	cout << k;
	return 0;
}
