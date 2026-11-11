#include <bits/stdc++.h>
using namespace std;
long long n, m;
const int N = 5e5 + 5;
int a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	long long c = 0;

	for (int i = 1; i <= n; i++) {

		long long num = a[1];
		long long k = 0;
		k = a[i] * i - num;

		if (k - a[i] < m) {
			num += a[i];
		} else {
			c = i;
			break;
		}
	}

	cout << c;
	return 0;
}