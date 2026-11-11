#include <iostream>
#include <string>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	if (s1.substr(0, 2) != s2.substr(0, 2)) {
		cout << "1000";
		return 0;
	}
	char seat1 = s1[2], seat2 = s2[2];
	if ((seat1 == 'D' && seat2 == 'E') || (seat1 == 'E' && seat2 == 'D')) {
		cout << "1111";
		return 0;
	}
	if ((seat1 <= 'C' && seat2 >= 'D') || (seat2 <= 'C' && seat1 >= 'D')) {
		cout << "1100";
		return 0;
	}
	if ((seat1 == 'A' && seat2 == 'C') || (seat1 == 'C' && seat2 == 'A')) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}