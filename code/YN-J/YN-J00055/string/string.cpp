#include <bits/stdc++.h>
using namespace std;

long long n, A, j = 1, g, ans;
long long a[200000];
char c[200000], c2[200000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (long long i = 1; i <= n; i++) {
		A += a[i];
	}
	for (long long i = 1; i <= A; i = i) {
		for (long long y = 1; y <= a[j]; y++) {
			c2[i] = c[j];
			i++;
		}
		j++;
	}
	if (A % 2 == 0) {
		g = A / 2;
		for (long long i = 1; i < g; i++) {
			if (c2[j - i + 1] != c2[j + i]) {
				ans++;
			}
		}
	} else {
		g = A / 2 + 1;
		for (long long i = 1; i < g; i++) {
			if (c2[j - i] != c2[j + i]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}