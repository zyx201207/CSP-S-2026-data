#include <bits/stdc++.h>
using namespace std;

long long a[200009];
char b[200009];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	long long r = n, l = 1;
	long long cnt = 0;
	while (r >= l) {
		if (b[r] == b[l]) {
			if (a[r] > a[l]) {
				a[r] -= a[l];
				l++;
			} else if (a[r] < a[l]) {
				a[l] -= a[r];
				r--;
			} else {
				l++;
				r--;
			}
		} else {
			if (a[r] > a[l]) {
				a[r] -= a[l];
				cnt += a[l];
				l++;
			} else if (a[r] < a[l]) {
				a[l] -= a[r];
				cnt += a[r];
				r--;
			} else {
				cnt += a[r];
				r--;
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
}
