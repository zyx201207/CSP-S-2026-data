#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "", s1, s2, s3;
	int num;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> num >> c;
		for (int i = 0; i < num; i++) {
			s += c;
		}
	}
	int sum = 0;
	double d = (s.size() * 1.0) / 2;
	int d1 = (int)d;
	for (int i = 0; i < (int)d + (d - d1 > 0 ? 1 : 0); i++) {
		s1 += s[i];
	}
	s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1.size() + s2.size() != s.size()) {
		s2.erase(s2.begin());
	}
	s1 += s2;
	for (int i = 0;;) {
		if (s == s1) {
			cout << sum;
			return 0;
		}
		if (s[i] != s1[i]) {
			s[i] = s1[i];
			sum++;
			i++;
		} else {
			i++;
		}

	}
	return 0;
}
/*
FUCK THIS IS SO HARD!!!!!
IF I CAN STUDY HARD THEN THIS ISN'T HARD.
*/
//FUCK YOu CCF
/*
3
2 a
2 b
1 c

*/