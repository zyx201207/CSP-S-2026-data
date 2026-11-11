#include <bits/stdc++.h>
using namespace std;
bool e (char c) {
	if (c == 'A' || c == 'B' || c == 'C') return 1;
	return 0;
}
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	char z1 = s1 [2];
	char z2 = s2 [2];
	s1.pop_back ();
	s2.pop_back ();
	if (s1 == s2) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if ((e (z1) && e (z2)) || !(e (z1) || e (z2))) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if (z1 == 'A' || z1 == 'C') {
		if (z2 == 'B') {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if (z1 == 'B') {
		if (z2 == 'A' || z2 == 'C') {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if (z1 == 'D') {
		if (z2 == 'F') {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		if (z2 == 'D') {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	return 0;
} 
