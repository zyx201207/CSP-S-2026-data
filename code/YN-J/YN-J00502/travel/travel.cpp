#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s_1, s_2, s_3, s_4;
	cin >> s_1 >> s_2 >> s_3 >> s_4;
	if (s_1 == s_3) {
		if (s_2.substr(0, 2) == s_4.substr(0, 2)) {
			if ((s_2[2] == 'A' && s_4[2] == 'B') || (s_2[2] == 'A' && s_4[2] == 'C') || (s_2[2] == 'B' && s_4[2] == 'A')
			        || (s_2[2] == 'B' && s_4[2] == 'C') || (s_2[2] == 'C' && s_4[2] == 'A') || (s_2[2] == 'C' && s_4[2] == 'B')) {
				if (abs(int(s_2[2]) - int(s_4[2])) == 1) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else if ((s_2[2] == 'D' && s_4[2] == 'F') || (s_2[2] == 'F' && s_4[2] == 'D')) {
				cout << "1111";
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}

