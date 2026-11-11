#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool chkside(char x, char y) {
	if((x >= 'A' && x <= 'C') && (y >= 'A' && y <= 'C')) return true;
	else if((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) return true;
	else return false;
}
bool chkseat(char x, char y) {
	if(x == 'C' && y == 'D') return false;
	if(x == 'D' && y == 'C') return false;
	if(x == 'D' && y == 'F') return true;
	if(x == 'F' && y == 'D') return true;
	return abs(x - y) == 1;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = (c1 == c2), b = (s1.substr(0, 2) == s2.substr(0, 2)), c = chkside(s1[2], s2[2]);
	cout << a << (a && b) << ((a && b) && c) << (a && b && c && chkseat(s1[2], s2[2]));
	return 0;
}
