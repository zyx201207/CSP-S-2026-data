#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] != c2[0] || c1[1] != c2[1]) {
		cout << "0000";
	} else if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000";
	} else if (s1[2] <= 'C' && s2[2] <= 'C') {
		if (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2]) {
			cout << "1111";
		} else {
			cout << "1110";
		}
	} else if (s1[2] >= 'D' && s2[2] >= 'D') {
		cout << "1111";
	} else {
		cout << "1100";
	}
	return 0;
}