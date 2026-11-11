#include <bits/stdc++.h>
using namespace std;

long long a[500001];
long long b[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = a[2] - a[1];
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j < i; j++) {
			b[i] = b[i] + j * k;
		}
	}
	long long ma = 0;
	for (long long i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == b[i]) {
				if (i > ma) {
					ma = i;
				}
			} else if (j > b[i] && j < b[i + 1]) {
				if (i > ma) {
					ma = i;
				}
			}
		}

	}
	cout << ma;



	return 0;
}