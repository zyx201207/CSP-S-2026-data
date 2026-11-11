#include <bits/stdc++.h>
using namespace std;
long long d[1000000];
long long f[1000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long a, s;
	cin >> a >> s;
	for (long long i = 1; i <= a; i++) {
		cin >> d[i];
	}
	sort(d + 1, d + 1 + a);
	for (long long i = 1; i <= a; i++) {
		for (long long j = 1; j <= i; j++) {
			f[i] += d[i] - d[j];
		}
	}
	sort(f + 1, f + 1 + a - 1);
	long long k = 0;
	for (long long i = 1; i <= a; i++) {
		if (f[i] <= s) {
			k = i;
		}
	}
	cout << k;
	return 0;
}

