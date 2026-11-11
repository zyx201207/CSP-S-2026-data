#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, s3, a, b;
char c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		s3 += "1";
	} else {
		cout << "0000";
		return 0;
	}

	for (int i = 0; i < 2; i++) {

		a += s1[i];
		b += s2[i];
	}

	c = s1[2];
	d = s2[2];

	if (a == b) {
		s3 += "1";

		if ((c == 'A' || c == 'B' || c == 'C') && (d == 'A' || d == 'B' || d == 'C')
		        || (c == 'D' && d == 'F') || (c == 'F' && d == 'D')) {
			s3 += "1";

			if ((c == 'A' && d == 'B') || (c == 'B' && d == 'A') || (c == 'B' && d == 'C') || (c == 'C' && d == 'B')
			        || (c == 'D' && d == 'F') || (c == 'F' && d == 'D')) {
				s3 += "1";
			} else {
				s3 += "0";
			}
		} else {
			s3 += "00";
		}
	} else {
		s3 += "000";
	}

	cout << s3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}