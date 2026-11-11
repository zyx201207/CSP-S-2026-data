# include <bits/stdc++.h>
# define ll long long

using namespace std;

string c1, s1, c2, s2;

int main () {
	
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1.substr (0, 2) == s2.substr (0, 2)) {
			cout << 1;
			ll x = 2, y = 2;
			if (s1[2] == 'A') x = 1;
			if (s1[2] == 'B') x = 1;
			if (s1[2] == 'C') x = 1;
			if (s2[2] == 'A') y = 1;
			if (s2[2] == 'B') y = 1;
			if (s2[2] == 'C') y = 1;
			if (x == y) {
				cout << 1;
				ll t1, t2;
				if (s1[2] == 'A') t1 = 1;
				if (s1[2] == 'B') t1 = 2;
				if (s1[2] == 'C') t1 = 3;
				if (s1[2] == 'D') t1 = 4;
				if (s1[2] == 'F') t1 = 5;
				
				if (s2[2] == 'A') t2 = 1;
				if (s2[2] == 'B') t2 = 2;
				if (s2[2] == 'C') t2 = 3;
				if (s2[2] == 'D') t2 = 4;
				if (s2[2] == 'F') t2 = 5;
				
				if (t1 - t2 == 1 || t2 - t1 == 1)
					cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	
	return 0;
}
