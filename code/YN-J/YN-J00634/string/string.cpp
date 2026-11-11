#include <bits/stdc++.h>
using namespace std;
long long a[200009];
char b[200009];
vector<char>s1;
vector<char>s2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long x = 0;
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		x += a[i];
	}
	long long k = 0;
	long long m = x / 2;
	for (long long i = 1; i <= n; i++) {
		long long s;
		if (m - k >= a[i]) {
			s = a[i];
		} else {
			s = m - k;
		}
		if (k + s <= m) {
			k += s;
			while (s--) {
				s1.push_back(b[i]);
			}
		}
	}
	k = 0;
	for (long long i = n; i >= 1; i--) {
		long long s;
		if (m - k >= a[i]) {
			s = a[i];
		} else {
			s = m - k;
		}
		if (k + s <= m) {
			k += s;
			while (s--) {
				s2.push_back(b[i]);
			}
		}
	}
	for (long long i = 0; i <= m; i++) {
		if (s1[i] != s2[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}