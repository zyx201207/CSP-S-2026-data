#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s, s1;

	while (n--) {
		long long a;
		char c;
		cin >> a >> c;
		for (int i = 1; i <= a; i++) {
			s += c;
		}
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		s1 += s[i];
	}
	long long sum = 0;
	if (s == s1) {
		cout << 0;
		return 0;
	} else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s1[i]) {
				s1[i] = s[i];
				sum++;
			}
		}
		cout << sum;
	}
	return 0;
}