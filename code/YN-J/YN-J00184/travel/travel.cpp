#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, s;
char n, m;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	n = s2[s2.size() - 1];
	s2[s2.size() - 1] = '0';
	m = s1[s1.size() - 1];
	s1[s1.size() - 1] = '0';
	if (c1 == c2) {
		s += '1';
		if (s1 == s2) {
			s += '1';
			if ((m == 'C' && n == 'D') || (n == 'C' && m == 'D')) {
				s += '0';
				s += '0';
			} else {
				s += '1';
				if (m - n == 1 || n - m == 1) {
					s += '1';
				} else {
					s += '0';
				}
			}
		} else {
			s += '0';
			s += '0';
			s += '0';
		}
	} else {
		s += '0';
		s += '0';
		s += '0';
		s += '0';
	}
	cout << s;
	return 0;
}