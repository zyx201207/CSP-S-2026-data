#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s;
	for (long long i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		string l;
		cin >> l;
		for (long long i = 1; i <= x; i++) {
			s += l;
		}
	}
	string s1;
	for (long long i = s.size() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	long long sum = 0;
	for (long long i = 0; i <= s.size() - 1; i++) {
		if (s[i] != s1[i]) {
			sum += 1;
		}
	}
	cout << sum / 2;
	return 0;
}