#include <bits/stdc++.h>
using namespace std;
string c1, s2, c3, s4;
string qian;

int main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	cin >> c1 >> s2 >> c3 >> s4;
	if (c1 == c3) {
		if (s2 == s4) {
			cout << "1001";
		} else {
			cout << "1111";
		}
	} else {
		if (s2 == s4) {
			cout << "0000";
		} else {
			cout << "0110";
		}
	}






	return 0;
}