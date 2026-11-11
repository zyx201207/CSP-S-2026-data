#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string c1, s1, c2, s2;
string res;
inline bool samesite(char a, char b) {
	if ((a >= 'A' && a <= 'C') && (b >= 'A' && b <= 'C')) return true;
	if ((a == 'D' && a == 'F') && (b == 'D' && b == 'F')) return true;
	return false;
	
}
inline bool near(char a, char b) {
	switch (a) {
	case 'A':
	case 'C':
		return b == 'B';
	case 'D':
		return b == 'F';
	case 'F':
		return b == 'D';
	default:
	    return b == (a - 1) || b == (a + 1);
	}
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << endl;
		return 0;	
	}
	res += "1";
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000" << endl;
		return 0;
	}
	if (!samesite(s1[2], s2[2])) {
		cout << "1100" << endl;
		return 0;
	}
	if (near(s1[2], s2[2])) cout << "1111" << endl;
	else cout << "1110" << endl;
	return 0;	
}
