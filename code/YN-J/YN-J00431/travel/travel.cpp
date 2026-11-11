#include <bits/stdc++.h>
using namespace std;

struct node {
	int c, a;
	char s;
} p[5];
string s1, s2 = "0000";

int main() {
	freopen("travel.in", "r", stdin);
	fropen("travel.out", "w", stdout);
	cin >> p[1].c >> p[1].a >> p[1].s >> p[2].c >> p[2].a >> p[2].s;

	if (p[1].c != p[2].c) {
		cout << s2;
		return 0;
	} else {
		s1 += '1';

		if (p[1].a == p[2].a) {
			s1 += '1';

			if (( (p[1].s >= 'A' && p[1].s <= 'C') && (p[2].s >= 'A' && p[2].s <= 'C') )
			        || ((p[1].s >= 'D' && p[1].s <= 'F') && (p[2].s >= 'D' && p[2].s <= 'F'))) {
				s1 += '1';

				if ((p[1].s + p[2].s == 'A' + 'B') || (p[1].s + p[2].s == 'B' + 'C') || (p[1].s + p[2].s == 'D' + 'F')) {
					s1 += '1';
				} else {
					s1 += '0';
				}

			} else {
				s1 += "00";
			}
		} else {
			s1 += "000";
			cout << s1;
			return 0;
		}
	}

	cout << s1;
	return 0;
}