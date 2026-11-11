#include <bits/stdc++.h>
using namespace std;
long long a[300000];
char c[300000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	long long sun = 0, u = 0, l = 1, r = n;
	while (l < r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else {
				l++;
				r--;
			}
		} else {
			if (a[l] < a[r]) {
				a[r] -= a[l];
				sun += a[l];
				l++;
			} else if (a[l] > a[r]) {
				a[l] -= a[r];
				sun += a[r];
				r--;
			} else {
				sun += a[l];
				l++;
				r--;
			}
		}
	}
	cout << sun;
	return 0;
}