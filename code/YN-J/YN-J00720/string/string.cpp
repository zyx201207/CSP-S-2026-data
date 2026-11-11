#include <bits/stdc++.h>
using namespace std;
long l = 0, r, mi = 0, a[100000000];
char s[100000000];
long n;

void z() {
	r = n - 1;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> s[i];
	while (l <= r) {
		if (a[l] > a[r]) {
			if (s[l] != s[r])
				mi += a[r];
			a[l] -= a[r];
			a[r] = 0;
		} else {
			if (s[l] != s[r])
				mi += a[l];
			a[r] -= a[l];
			a[l] = 0;
		}
		if (!a[l])
			l++;
		if (!a[r])
			r--;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	z();
	cout << mi;
	return 0;
}