#include <bits/stdc++.h>
using namespace std;
string s, c, s1, c1; //c-->³µÏáºÅ£»s-->×ùÎ»ºÅ
map<char, int> mp;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	mp['A'] = 1;
	mp['B'] = 1;
	mp['C'] = 1;
	cin >> c >> s >> c1 >> s1;
	if (c == c1) {
		cout << 1;
		if (s.substr(0, 2) == s1.substr(0, 2)) {
			cout << 1;
			if (mp[s[2]] == mp[s1[2]]) {
				cout << 1;
				//ÏàÁÚ
				if ((s[2] - '0') == (s1[2] - '0') + 1)
					cout << 1;
				else if ((s[2] - '0') == (s1[2] - '0') - 1)
					cout << 1;
				else
					cout << 0;
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";

	return 0;
}