#include <bits/stdc++.h>
using namespace std;
long long a[100000001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, x = 0, s = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	x = m;
	for (long long  i = 1; i <= n - 1; i++) {
		a[i] = a[i] + 1;
		x = x - (a[i + 1] - a[i]) * i;
		if (x >= 0) {
			s = i ;
		}

	}
	cout << s + 1;
}