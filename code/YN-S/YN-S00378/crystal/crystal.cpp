#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (int i = n; i >= 1; i--) {

		long long t = m, j = i, sum = 0;

		while (t > 0 && j >= 0) {
			t = t - abs(a[i] - a[j]);
			sum++;
			j--;
		}


		ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}