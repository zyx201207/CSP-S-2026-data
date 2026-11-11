#include <bits/stdc++.h>
using namespace std;
long long a[100000001];

int main() {
	long long n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cnt = a[n - 1];
	for (int i = n - 1; i > 0; i--) {
		if (a[i] == a[i + 1] && m == 2) {
			cout << a[i];
			return 0;
		}
	}
	for (int i = n - 1; i > n - m - 1; i--) {
		cnt = (cnt & a[i]);
	}
	cout << cnt;
	return 0;
}