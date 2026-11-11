#include <iostream>
#include <cstring>
#include <map>
using namespace std;
string c1, s1, c2, s2;
map<char, int> ma;
void init() {
	ma['A'] = 1;
	ma['B'] = 1;
	ma['C'] = 1;
	ma['D'] = 0;
	ma['F'] = 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	init();
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		if ((s1[0] != s2[0]) || (s1[1] != s2[1])) {
			cout << "1000";
		} else {
			if (ma[s1[2]] != ma[s2[2]]) {
				cout << "1100";
			} else {
				if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			}
		}
	}
	return 0;
}
