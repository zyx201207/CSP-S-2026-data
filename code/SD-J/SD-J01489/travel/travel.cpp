#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string c1, s1, c2, s2;
bool check(char ch) {
	return ((ch == 'E') || (ch == 'F'));
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (check(s1[2]) == check(s2[2])) {
		if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')) {
			cout << "00";
			return 0;		
		}
		cout << 1;	
	}
	if (abs(int(s1[2]) - int(s2[2])) == 1) cout << 1;
	else cout << 0;
	return 0;
}
