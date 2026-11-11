#include <bits/stdc++.h>
using namespace std;
long long m, sum = 0;
long long a[1000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		long long m1 = m;
		long long a1 = a[i];
		long long cnt = 0;
		for (int j = i; j >= 1; j--) {
			long long da = a1 - a[j];
			if (m1 >= da) {
				m1 = m1 - da;
				cnt++;
			} else {
				break;
			}

		}
		sum = max(sum, cnt);
	}
	cout << sum;
	return 0;
}