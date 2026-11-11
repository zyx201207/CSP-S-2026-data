#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	bool ok = false;

	if (c1 == c2) {
		cout << 1;
		ok = true;
	} else
		cout << 0;

	bool flag = false;

	if (ok == true && s1[0] == s2[0] && s1[1] == s2[1]) {
		flag = true;
		cout << 1;
	} else {
		cout << 0;
	}

	if (flag == true) {
		if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' && s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			cout << 1;
		else if (s1[2] == 'D' || s1[2] == 'F' && s2[2] == 'D' || s2[2] == 'F')
			cout << 1;
		else
			cout << 0;
	} else {
		cout << 0;
	}

	if (ok == true && flag == true) {
		if (s1[2] == 'A' && s2[2] == 'B')
			cout << 1;
		else if (s1[2] == 'B' && s2[2] == 'A' || s2[2] == 'C')
			cout << 1;
		else if (s1[2] == 'C' && s2[2] == 'B')
			cout << 1;
		else if (s1[2] == 'D' && s2[2] == 'F')
			cout << 1;
		else if (s1[2] == 'F' && s2[2] == 'D')
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;

	return 0;
}