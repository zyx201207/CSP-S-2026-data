#include <bits/stdc++.h>
using namespace std;
int a[10000005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	long long k = a[n - 1];
	bool ok = true;
	for (int i = n - 1; i >= m - 1; i--) {
		if (a[n - i] == k) {
			ok = true;
		} else {
			ok = false;
			break;
		}
	}
	if (ok == 1) {
		cout << k;
		return 0;
	}
	a[1] &= a[2];
	cout << a[1];
	return 0;
}