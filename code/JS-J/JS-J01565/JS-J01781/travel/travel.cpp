#include <iostream>
#include <string>
using namespace std;

string c1, s1, c2, s2;
bool mp[128];

inline bool checktyp(char a, char b) {
	return mp[(int)a] == mp[(int)b];
}

inline bool checkxl(char a, char b) {
	if (a > b) {
		char t=a;
		a = b;
		b = t;
	}
	return (a=='B'&&b=='C') || (a=='A'&&b=='B') || (a=='D'&&b=='F');
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	mp['A'] = mp['B'] = mp['C'] = 1;
    cin >> c1 >> s1 >> c2 >> s2;
    string row1 = s1.substr(0, 2), row2 = s2.substr(0, 2);
    char col1 = s1[2], col2 = s2[2];
    if (c1 == c2) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1==c2 && row1==row2) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1==c2 && row1==row2 && checktyp(col1, col2)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	if (c1==c2 && row1==row2 && checktyp(col1, col2) && checkxl(col1, col2)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
    return 0;
}
