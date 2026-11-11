//齐君豪 西安市含光中学 SN-J00750
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2, t1, t2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> t1 >> t2;
	if(s1 == t1) {
		cout << "1";
		if(s2[0] == t2[0] && s2[1] == t2[1]) {
			cout << "1";
			int _s = s2[2] - 'A';
			int _t = t2[2] - 'A';
			if((_s <= 2 && _t <= 2) || (_s >= 3 && _s <= 4 && _t >= 3 && _t <= 4)) {
				cout << "1";
				if(abs(_s - _t) == 1)
					cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
} 
