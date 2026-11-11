#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s;
	cin >> s;
	for (int  i = 0; i < s.size(); i++) {
		if (s[i] != '1' ) {
			cout << "1" << "1" << "1" << "1";
			break;
		} else if (s[i] == '2') {
			cout << "1" << "1" << "1" << "0";
		} else if (s[i] == '3' ) {
			cout << "1" << "1" << "0" << "0";
		} else if (s[i] == '4') {
			cout << "1" << "0" << "0" << "0";
		} else if (s[i] != '1' ) {

			cout << "0" << "0" << "0" << "0";
			break;
		}
	}
	return 0;
}