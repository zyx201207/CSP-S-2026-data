#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, sum = 0;
	string s = "", s1 = "", s2 = "";
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long x;
		char c;
		cin >> x >> c;
		for (long long i = 0; i < x; i++) {
			s += c;
		}
	}
	if (s.size() % 2 == 0) {
		for (long long i = 0; i < s.size(); i++) {
			if (i < s.size() / 2) {
				s1 += s[i];
			} else {
				s2 += s[i];
			}
		}
	} else {
		for (long long i = 0; i < s.size(); i++) {
			if (i < s.size() / 2) {
				s1 += s[i];
			}
			if (i > s.size() / 2) {
				s2 += s[i];
			}
		}
	}
	for (long long i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}