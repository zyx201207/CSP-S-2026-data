#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	for (int i = 1; i <= 2; i++) {

		if (c1 != "01" && c1 != "16" && c1 <= "17" && c2 != "01" && c2 != "16" && c2 <= "17") {

			if (c1 == c2)
				cout << "1";
			else {
				cout << "0";
			}
		} else {
			cout << "0";
		}

		if (s1[0] == s2[0] && s1[1] == s2[1] && s1[0] <= "1" && s1[1] <= "7" && s1[2] <= "F" && s2[0] <= "1" && s2[1] <= "7"
		        && s2[2] <= "F") {

			if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)	{
				cout << "1";
			} else {
				cout << "0";
			}
		} else {
			cout << "0";
		}
	}

	return 0;
}