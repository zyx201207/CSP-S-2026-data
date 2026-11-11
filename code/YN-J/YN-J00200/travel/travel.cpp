#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	int zwh1[2], zwh2[2];
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << "1";
	else {
		cout << "0000" << '\n';
		//break;
	}
	for (int i = 0; i < 2; i++) {
		zwh1[i] = s1[i] - '0';
		zwh2[i] = s2[i] - '0';
	}
	char a1 = s1[2];
	char a2 = s2[2];
	if (zwh1[0] != zwh2[0] || zwh1[1] != zwh2[1]) {
		cout << "000" << '\n';
		//break;
	}

	else
		cout << "1";
	if (((a1 == 'D' && a2 == 'C') || (a2 == 'D' && a1 == 'C'))
	        || (a1 - a2 > 1 && (a1 != 'D' || a1 != 'C'))) {
		cout << "00" << '\n';
		//	break;
	} else {
		if ((a1 == 'D' && a2 == 'F') || (a2 == 'D' && a1 == 'F'))
			cout << "1" << '\n';
		else {
			cout << "1" << '\n';
		}
		if ((a1 == 'D' || a1 == 'F') && (a2 == 'D' || a2 == 'F'))
			cout << "1" << '\n';
		if ((a1 - a2 == 1) && (a1 != 'C' || a1 != 'D'))
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}





	return 0;
}