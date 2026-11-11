#include <bits/stdc++.h>
using namespace std;
string s, ss, ssss, sss;
string ans = "";
map <char, int> mp;
map <char, int> mpl;

bool check (char ck, char cf) {
	if (ck == 'F' && cf == 'D')
		return true;
	if (ck == 'D' && cf == 'F')
		return true;
	return abs (mpl[ck] - mpl[cf]) <= 1;
}

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	mpl['A'] = 1;
	mpl['B'] = 2;
	mpl['C'] = 3;
	mp['A'] = 1;
	mp ['B'] = 1;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['F'] = 2;
	cin >> s >> ss >> sss >> ssss;
	if (s == sss) {
		cout << 1;
		if (ss.substr (0, 2) == ssss.substr (0, 2)) {
			cout << 1;
			if (mp [ss[2]] == mp [ssss[2]]) {
				cout << 1;
				if (check (ss[2], ssss[2])) {
					cout << 1;
				} else
					cout << "0";
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}