#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	char a1 = s1[0];
	char a2 = s1[1];
	char b1 = s2[0];
	char b2 = s2[1];
	if (a1 == b1 && a2 == b2) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	char a = s1[2];
	char b = s2[2];
	if (a == 'F') {
		if (b == 'D') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (a == 'D') {
		if (b == 'F') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (a == 'C') {
		if (b == 'B') {
			cout << "11";
			return 0;
		}
		else if (b == 'A') {
			cout << "10";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (b == 'C') {
		if (a == 'B') {
			cout << "11";
			
		}
		else if (a == 'A') {
			cout << "10";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (a == 'B') {
		if (b == 'A') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (b == 'B') {
		if (a == 'A') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (a == 'A') {
		if (b == 'B') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		}
	}
	if (b == 'A') {
		if (a == 'B') {
			cout << "11";
			return 0;
		}
		else {
			cout << "00";
			return 0;
		} 
	}
	return 0;
} 
