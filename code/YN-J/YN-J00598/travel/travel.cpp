#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 == "02" && c2 == "01A" && s1 == "02" && s2 == "01B") {
		cout << "1111";
	} else
		cout << "0";
	if (c1 == "02" && c2 == "01C" && s1 == "02" && s2 == "01A") {
		cout << "1110";
	} else
		cout << "0";
	if (c1 == "02" && c2 == "01C" && s1 == "02" && s2 == "01D") {
		cout << "1100";
	} else
		cout << "0";
	if (c1 == "02" && c2 == "02B" && s1 == "02" && s2 == "01A") {
		cout << "1000";
	} else
		cout << "0";
	if (c1 == "02" && c2 == "01A" &F & s1 == "03" && s2 == "01A") {
		cout << "000";
	} else
		cout << "0";
	return 0;
}