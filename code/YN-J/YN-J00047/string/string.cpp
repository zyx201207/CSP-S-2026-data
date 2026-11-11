#include <bits/stdc++.h>
using namespace std;
long long n, a;
long long x;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s, c, s1;
	for (long long i = 1; i <= n; i++) {
		cin >> a >> c;
		for (long long i = 1; i <= a; i++)
			s += c;
	}
	long long len = s.size();
	for (long long i = len - 1; i >= 0; i--) {
		s1 += s[i];
	}
	if (s1 == s)
		cout << 0;
	else if (len % 2 == 1) {
		for (long long i = 0; i < len / 2; i++) {
			if (s1[i] != s[i])
				x++;
		}
		cout << x;
	} else {
		for (long long i = 0; i < len / 2; i++) {
			if (s1[i] != s[i])
				x++;
		}
		cout << x;
	}

	return 0;
}