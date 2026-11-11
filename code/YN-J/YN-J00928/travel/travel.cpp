#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;

void checks(string c1, string c2, string s1, string s2) {
	if (c1 == c2) {
		cout << 1;
		if (s1[1] + s1[0] * 10 == s2[1] + s2[0] * 10) {
			cout << 1;


			if (((char(s1[2]) == 'A' || char(s1[2]) == 'B' || char(s1[2]) == 'C') && (char(s2[2]) == 'A' || char(s2[2]) == 'B'
			        || char(s2[2]) == 'C')) || ((char(s1[2]) == 'D' || char(s1[2]) == 'F') && (char(s2[2]) == 'D' || char(s2[2]) == 'F'))) {
				cout << 1;
				int a, b;
				a = char(s1[2]) - 'A';
				b = char(s2[2]) - 'A';
				if ((a != 3 && a != 4) && (b != 3 && b != 4)) {
					if (abs(a - b) == 1)
						cout << 1;
					else
						cout << 0;
				} else if (a + b - 7 == 0) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}

	} else {
		cout << 0 << 0 << 0 << 0;
	}
}


int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	checks(c1, c2, s1, s2);
	return 0;

}