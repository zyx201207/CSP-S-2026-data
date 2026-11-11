#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("crystal1.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long a[100000];
	long long b[100000];
	long long n, m, index = 0;
	cin >> n >> m;
	int m2 = m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[index];
		index++;
	}
	sort(a, a + index, greater<int>());
	for (long long i = 0; i < index; i++) {
		m = m2;
		long long cnt = 0;
		long long mubiao = a[i];
		for (long long j = i; j < index; j++) {
			if (mubiao - a[j] > m) {
				continue;
			}
			m -= mubiao - a[j];
			cnt++;
		}
		b[i] = cnt;
	}
	long long mx = -200000000000;
	for (long long i = 0; i < index; i++) {
		if (b[i] >= mx) {
			mx = b[i];
		}
	}
	cout << mx;

	return 0;
}