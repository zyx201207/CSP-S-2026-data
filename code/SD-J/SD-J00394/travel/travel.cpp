# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

string c1, c2, s1, s2;
 
signed main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	fst;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << endl;
		return 0;
	}
	cout << "1";
	string p1 = s1.substr (0, 2);
	string p2 = s2.substr (0, 2);
	if (p1 != p2) {
		cout << "000" << endl;
		return 0;
	}
	cout << "1"; 
	char ce1 = s1[2];
	char ce2 = s2[2];
	{
		if (ce1 == 'A') {
			if (ce2 == 'B' || ce2 == 'C') {
				cout << "1"; 
			} 
			else {
				cout << "00";
				return 0;
			}
		}
		else if (ce1 == 'B') {
			if (ce2 == 'A' || ce2 == 'C') {
				cout << "1"; 
			} 
			else {
				cout << "00";
				return 0;
			}
		}
		else if (ce1 == 'C') {
			if (ce2 == 'B' || ce2 == 'A') {
				cout << "1"; 
			} 
			else {
				cout << "00";
				return 0;
			}
		}
		else if (ce1 == 'D') {
			if (ce2 == 'E') {
				cout << "1"; 
			} 
			else {
				cout << "00";
				return 0;
			}
		}
		else if (ce1 == 'E') {
			if (ce2 == 'D') {
				cout << "1"; 
			} 
			else {
				cout << "00";
				return 0;
			}
		}
	}
	{
		if (ce1 == 'A') {
			if (ce2 == 'B') {
				cout << "1" << endl;
				return 0;
			}
			else {
				cout << "0" << endl;
				return 0;
			}
		}
		else if (ce1 == 'B') {
			if (ce2 == 'A' || ce2 == 'C') {
				cout << "1" << endl;
				return 0;
			}
			else {
				cout << "0" << endl;
				return 0;
			}
		}
		else if (ce1 == 'C') {
			if (ce2 == 'B') {
				cout << "1" << endl;
				return 0;
			}
			else {
				cout << "0" << endl;
				return 0;
			}
		}
		else if (ce1 == 'D') {
			if (ce2 == 'E') {
				cout << "1" << endl;
				return 0;
			}
			else {
				cout << "0" << endl;
				return 0;
			}
		}
		else if (ce1 == 'E') {
			if (ce2 == 'D') {
				cout << "1" << endl;
				return 0;
			}
			else {
				cout << "0" << endl;
				return 0;
			}
		}
	}
	return 0;
}

