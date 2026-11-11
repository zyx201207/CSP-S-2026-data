#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5;
long long a[N + 5];
char c[N + 5];

int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout); 
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> c[i]; 
	}
	long long ans = 0;
	long long l = 1, r = n;
	long long ll = a[1], rr = a[n];
	while (l < r) {
		if (c[l] != c[r]) {
			if (ll < rr) {
				ans += ll;
				rr -= ll;
				ll = a[++l];
			}
			else if (rr < ll) {
				ans += rr;
				ll -= rr;
				rr = a[--r];
			}
			else if (rr == ll) {
				ans += rr;
				ll = a[++l];
				rr = a[--r];
			}
		}
		else {
			if (ll > rr) {
				ll -= rr;
				rr = a[--r];
			}
			else if (rr > ll) {
				rr -= ll;
				ll = a[++l];
			}
			else {
				rr = a[--r];
				ll = a[++l];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
