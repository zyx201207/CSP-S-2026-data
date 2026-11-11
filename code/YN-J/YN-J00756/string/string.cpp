#include <bits/stdc++.h>
using namespace std;

int add(string s) {
	string s1 = s;
	reverse(s1.begin(), s1.end());
	if (s1 == s) {
		return 1;
	} else
		return 0;
}
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string ss, s1, s2;
	int n, a, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> ss;
		for (int i = 1; i <= a; i++) {
			s += ss;
		}
	}
	if (add(s) == 1) {
		cout << 0;
		return 0;
	} else if (s.size() % 2 == 0) {
		for (int i = 0; i <= (s.size() - 1) / 2; i++) {
			s1[i] = s[i];
		}
		for (int i = (s.size() - 1) / 2 + 1; i <= s.size() - 1; i++) {
			s2[i] = s[i];
		}
		reverse(s2.begin(), s2.end());
		for (int i = 0; i <= (s.size() - 1) / 2; i++) {
			if (s1[i] != s2[i]) {
				cnt++;
			}
		}
	} else if (s.size() % 2 != 0) {
		for (int i = 0; i <= (s.size() - 1) / 2 - 1; i++) {
			s1[i] = s[i];
		}
		for (int i = (s.size() - 1) / 2 + 1; i <= s.size() - 1; i++) {
			s2[i] = s[i];
		}
		reverse(s2.begin(), s2.end());
		for (int i = 0; i <= (s.size() - 1) / 2 - 1; i++) {
			if (s1[i] != s2[i]) {
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}
