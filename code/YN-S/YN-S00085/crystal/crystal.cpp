#include <bits/stdc++.h>
using namespace std;

long long a[110001];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= 0) {
			a[i] = a[i] * -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[1] + a[2];
		return 0;
	}

	return 0;

}