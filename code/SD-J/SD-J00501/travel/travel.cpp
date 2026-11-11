#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string c1, c2;

string s1, s2;

inline bool check_ce (char r, char x) {
	if (r <= 'C' && x <= 'C') return true;
	if (r >= 'D' && x >= 'D') return true;
	return false;
}

inline bool check_lin (char r, char x) {
	if (r <= 'C' && x <= 'C') // abc
		if (r == x + 1 || x == r + 1) return true; // ab ba cb bc
	else if (r >= 'D' && x >= 'D') // df
		if ((r == 'D' && x == 'F') || (r == 'F' && x == 'D')) return true;
	return false;
}

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> c2 >> s1 >> s2;
	int cxr = c1[0] * 10 + c1[1], cxx = s1[0] * 10 + s1[1];
	if (c1 == s1) { // ≥µœ· 
		cout << 1;
		int r = c2[0] * 10 + c2[1], x = s2[0] * 10 + s2[1];
		if (r == x) { // ≈≈ 
			cout << 1;
			char R = c2[2], X = s2[2];
			if (check_ce(R, X)) { // Õ¨≤‡ 
				cout << 1;
				if (check_lin(R, X)) cout << 1 << endl;
				else cout << "0" << endl;
			} else cout << "00" << endl;
		} else cout << "000" << endl;
	} else cout << "0000" << endl;
	return 0;
}
