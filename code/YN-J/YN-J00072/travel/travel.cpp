#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char x = s1[2];
	char y = s2[2];
	if (c1 == c2) {
		cout << "1";
	} 
	else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0]&&s1[1]==s2[1]) {
		cout << "1";
	} 
	else {
		cout << "000";
		return 0;
	}
	if ((x != 'D' && y != 'C') || (x != 'C' && y != 'D')&&(x=='D'&&y=='F')||(x=='F'&&y=='D')||(x=='C'&&y=='B')||(x=='B'&&y=='A')||(x=='A'&&y=='B')) {
		cout << "1";
	} 
	else {
		cout << "00";
		return 0;
	}

	if (x - y == -1 || y - x == 1) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}
