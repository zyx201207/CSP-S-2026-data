#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string sa, sd ;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int h = 1;

	if (c1 == c2) {
		cout << 1;
		h = 0;
	} else
		cout << 0;
	sa = s1.substr(0, 2);
	sd = s2.substr(0, 2);
	int f = 1, b = 1;
//	cout << sa << " " << sd << endl;

	if (h == 0 && sa == sd) {
		cout << 1;
		f = 0;
	} else
		cout << 0;

	if (f == 0 && (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
	               || ((s1[2] == 'F' || s1[2] == 'D') && (s2[2] == 'F' || s2[2] == 'D')))) {
		cout << 1;
		b = 0;
	} else
		cout << 0;
	int a = (sa[1] - '0') * 10 + sa[2] - '0';
	int c = (sd[1] - '0') * 10 + sd[2] - '0';

	if (b == 0  && (sa == sd || abs(a - c) == 1) && (s1[2] == s2[2] || abs(s1[2] - s2[2]) == 1))
		cout << 1;
	else
		cout << 0;


	return 0;
}
