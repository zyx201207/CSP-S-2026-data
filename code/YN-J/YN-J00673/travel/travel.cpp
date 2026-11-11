#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, s;
	string b, s1;
	cin >> a >> s >> b >> s1;

	if (a != b ) {
		cout << "0000";
		return 0;
	}

	if (a == b )
		if (s[1] == s1[1])
			cout << "11";
		else {
			cout << '0';
		}

	if (a == b )
		if (s[1] == s1[1])
			if (s[s.size () - 1] != 'D' && s1[s1.size() - 1] != 'C' )
				if ( s1[s1.size() - 1] != 'C' && s1[s1.size() - 1] != 'D')
					cout << '1';
				else {
					cout << '0';
				}

	if (a == b )
		if (s[1] == s1[1])
			if (s[s.size () - 1] != 'D' && s1[s1.size() - 1] != 'C' )
				if ( s1[s1.size() - 1] != 'C' && s1[s1.size() - 1] != 'D')
					if (s[s.size() - 1] + 1 == s1[s1.size() - 1] || s[s.size() - 1]  == s1[s1.size() - 1] + 1)
						cout << '1';
					else {
						cout << '0';
					}

	return 0;
}
