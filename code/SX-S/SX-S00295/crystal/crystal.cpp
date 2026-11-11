#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n;
	long long m;
	bool flag = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			flag = 1;
		}
	}
	sort(a + 1, a + n + 1);
	if (n <= 5000) {
		long long s[500][500];
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				s[i][j] = a[j] - a[i];
			}
		}
		for (int i = n; i > 1; i--) {
			long long ans = 0;
			for (int j = 1; j < i; j++) {
				ans += s[j][i];
			}
			if (ans <= m) {
				cout << i;
				return 0;
			}
		}
	}



	if (flag == 0) {
		long long mm = m;
		long long i = 1;
		while (mm >= 0) {
			mm -= i;
			i++;
		}
		cout << min((i - 1), n);

	} else {
		long long e = a[2] - a[1];
		long long mm = m;
		long long i = 1;
		while (mm >= 0) {
			mm -= i * e;
			i++;
		}
		cout << min((i - 1), n);
	}
	return 0;
}
