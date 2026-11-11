#include <bits/stdc++.h>
using namespace std;

struct A {
	long long x;
	char y;
} a[10005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s;
	cout << s;
	for (long long i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		if (a[0].x >= 1000000) {
			a[i].x = a[i].x * 1.0 / 1000;
		}
		for (long long j = 0; j < a[i].x; j++) {
			s += a[i].y;
		}
	}
	long long m = s.size(), num = 0;
	for (long long i = 0; i < m / 2; i++) {
		if (s[i] != s[m - 1 - i]) {
			num++;
		}
	}
	if (a[0].x >= 1000000) {
		num *= 1000;
	}
	cout << num;
	return 0;
}