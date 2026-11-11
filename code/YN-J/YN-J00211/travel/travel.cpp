#include <bits/stdc++.h>
using namespace std;
string c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
		int ans1 = 0, ans2 = 0;
		char a1, a2;
		ans1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		ans2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		a1 = s1[2];
		a2 = s2[2];

		if (ans1 == ans2) {
			cout << 1;
			int z = 0, y = 0;

			if (a1 <= 'C')
				z++;
			else
				y++;

			if (a2 <= 'C')
				z++;
			else
				y++;

			if (z == 2 || y == 2) {
				cout << 1;


				if (abs(a1 - a2) == 1) {
					cout << 1;
				} else
					cout << "0";
			} else {
				cout << "00";
				return 0;
			}
		} else {
			cout << "000";
			return 0;
		}

		//if ()
	} else {
		cout << "0000";
	}
}