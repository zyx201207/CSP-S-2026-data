#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2)
		cout << 1;
	else {
		cout << "0000" << endl;
		return 0;
	}

	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;

		if (s1[2] + 0 >= 65 && s1[2] + 0 <= 67 && s2[2] + 0 >= 65 && s2[2] + 0 <= 67) {
			cout << 1;

			if (abs((s1[2] + 0) - (s2[2] + 0)) == 1)
				cout << 1;
			else
				cout << 0 << endl;
		} else if ((s1[2] + 0 == 68 && s2[2] + 0 == 70) || (s2[2] + 0 == 68 && s1[2] + 0 == 70))
			cout << "11" << endl;
		else
			cout << "00" << endl;
	} else
		cout << "000" << endl;
	return 0;
}