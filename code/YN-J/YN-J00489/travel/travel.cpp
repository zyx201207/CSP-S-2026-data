#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	int t1 = 20, t2 = 22, m1 = 21, m2 = 23;
	cin >> s1 >> s2 >> s3 >> s4;
	char c1, c2;
	cout << (s1 == s3);
	for (int i = 0; i <= 2; i++) {
		c1 = s2[2];
		if (i != 2) {
			if (s2[i] == '0' && i != 1)
				t1 = s2[i + 1] - '0';
			else if (s2[i - 1] != '0')
				m1 = s2[i] - '0';
		}

	}
	for (int i = 0; i <= 2; i++) {
		c2 = s4[2];
		if (i != 2) {
			if (s4[i] == '0' && i != 1)
				t2 = s4[i + 1] - '0';
			else if (s4[i - 1] != '0')
				m2 = s4[i] - '0';
		}

	}
	bool p1 = ((c1 == 'A' || c1 == 'B' || c1 == 'C') && (c2 == 'A' || c2 == 'B' || c2 == 'C'));
	bool p2 = (c1 - c2 == 1 || c2 - c1 == 1);
	bool p3 = ((c1 == 'D' || c1 == 'F') && (c2 == 'D' || c2 == 'F'));
	bool p4 = (s1 == s3);
	bool p5 = (t1 == t2 || m1 == m2);
	bool p6 = (c1 != 'D' && c2 != 'D');
	cout << (p4 && p5);
	cout << ((p4 && p5) && (p1 || p3));
	cout << ((p4 && p5) && (p3 || (p6 && p2)));
	return 0;
}