#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long a;
	char c, b;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	long x = 0;
	long y = s.length() - 1;
	long sum1 = 0, sum2 = 0;
	long m = x;
	long z = y;
	while (m != n) {
		if (s[m] != s[z]) {
			s[m] = s[z];
			sum1++;
		}
		m++;
		z--;
	}
	while (x != y) {
		if (s[x] != s[y]) {
			s[y] = s[x];
			sum2++;
		}
		x++;
		y--;
	}
	if (sum1 <= sum2) {
		cout << sum1;
	} else {
		cout << sum2;
	}
	return 0;
}