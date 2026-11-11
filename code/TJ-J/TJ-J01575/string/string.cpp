#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long a[N];
string s[N];
string m;
long long lon;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		for (long long j = 1; j <= a[i]; j++) {
			m += s[i];
		}
		lon += a[i];
	}
	double mid = 0;
	long long sum = 0;
	if (lon % 2 == 0) {
		mid = lon / 2;
		long long l = 1, r = lon;
		while (l <= mid && r > mid) {
			if (m[l] != m[r]) {
				sum++;
			}
			l++;
			r--;
		}
	} else if (lon % 2 == 1) {
		mid = lon / 2 + 1;
		long long l = 1, r = lon;
		while (l < mid || r > mid) {
			if (m[l] != m[r]) {
				sum++;
			}
			l++;
			r--;
		}
	}
	cout << sum;
	return 0;
}
