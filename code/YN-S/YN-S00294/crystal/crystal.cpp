#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m % 2 != 0) {
		cout << m / 2 + 1;
	} else {
		cout << m / 2;
	}
	return 0;
}
