#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}

	string strc = "", strs = "";

	for (int i = 0; i < 2; i++) {

		strc += s1[i];
		strs += s2[i];
	}

	if (strc == strs)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}

	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
		cout << 1;
	else {
		cout << "00";
		return 0;
	}

	if (abs(s1[2] - s2[2] ) == 1 || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F'))
		cout << 1;
	else {
		cout << "0";
		return 0;
	}

	return 0;
}