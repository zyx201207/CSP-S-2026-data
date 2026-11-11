#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n <= 5000) {
		sort(a + 1, a + n + 1);
		long long maxx = a[n];
		for (int i = 1; i <= n; ++i) a[i] = maxx - a[i];

		int len = 0;
		for (int i = n; i >= 1; --i) {
			long long sum = 0, ed = a[i];
			for (int j = i; j >= 1; --j) {
				sum += a[j] - ed;
				if (sum > m) {
//					cout << sum << " " << j + 1 << " " << i << endl;
					len = max(len, i - j);
					break;
				}
			}
			if (sum <= m) len = max(len, i);
		}

		cout << len << endl;
	} else {
		if (a[1] < a[2]) {
			int len = 0;
			long long sum = 0;
			long long maxx = a[n];
			for (int i = n; i >= 1; --i) {
				sum += maxx - a[i];
				if (sum > m) {
					len = max(len, n - i);
					break;
				}
			}
			if (sum <= m) len = max(len, n);
			cout << len << endl;
		} else {
			int len = 0;
			long long sum = 0;
			long long maxx = a[1];
			for (int i = 1; i <= n; ++i) {
				sum += maxx - a[i];
				if (sum > m) {
					len = max(len, i - 1);
					break;
				}
			}
			if (sum <= m) len = max(len, n);
			cout << len << endl;
		}

	}


	return 0;
}