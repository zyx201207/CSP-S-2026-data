#include <bits/stdc++.h>
using namespace std;

int main() {

	//TESE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	//READ
	string c_1, s_1, c_2, s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;

	//QUSETION-1
	if (c_1 == c_2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	//QUSETION-2
	if (s_1[0] == s_2[0] && s_1[1] == s_2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	//QUSETION-3
	if ( (s_1[2] > 'C' && s_2[2] > 'C') || (s_1[2] < 'D' && s_2[2] < 'D') ) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}

	//QUSETION-4
	if ((s_1[2] == 'A' && s_2[2] == 'C') || (s_1[2] == 'C' && s_2[2] == 'A')) {
		cout << "0";
	} else {
		cout << "1";
	}

	//END-100%AC
	return 0;
}