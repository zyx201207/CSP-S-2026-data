#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << '1';
		bool flag = 1;
		for (int i = 0; i <= 1; i++) {
			if (s1[i] != s2[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << '1';
			bool flag1 = 0, flag2 = 0;
			if (s1[2] >= 'A' && s1[2] <= 'C')
				flag1 = 1;
			if (s2[2] >= 'A' && s2[2] <= 'C')
				flag2 = 1;
			if (flag1 == flag2) {
				cout << '1';
				if (flag1 && flag2) {
					if (abs((s1[2] - 'A') - (s2[2] - 'A')) == 1)
						cout << '1';
					else
						cout << '0';
				} else {
					if (s1[2] == s2[2])
						cout << '0';
					else
						cout << '1';
				}
			} else
				cout << "00";
		} else
			cout << "000";

	} else
		cout << "0000";



	return 0;
}