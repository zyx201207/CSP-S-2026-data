#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n, a[N];
char c[N];
int sum;
int sum1;
signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	for (int l = 1, r = n; l <= r;) {
		if (c[l] != c[r]) {
			if (a[l] < a[r]) {
				sum += a[l];
				a[r] -= a[l];
				l++;
			}
			else if (a[l] > a[r]) {
				sum += a[r];
				a[l] -= a[r];
				r--;
			}
			else {
				sum += a[r];
				a[l] = a[r] = 0;
				l++, r--;
			}
		}
		else {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			}
			else if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			}
			else {
				a[l] = a[r] = 0;
				l++, r--;
			}
		}
	}
	cout << sum;
	return 0;
} 
