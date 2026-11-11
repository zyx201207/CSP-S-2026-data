#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int i = 0;
	cin >> i;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1[i] == s2[1] && s1[2] == s2[2]) {
		cout << "1";
		else {
			cout << "0";
		}
		if (s1[3] == 'A' && s2[3] == 'B' || s1[3] == 'A' && s2[3] == 'C' || s1[3] == 'B' && s2[3] == 'C' || s1[3] == 'B'
		        && s2[3] == 'A' || s1[3] == 'C' && s2[3] == 'A' || s1[3] == 'C' && s2[3] == 'B' || s1[3] == "D" && s2[3] == "F"
		        || s1[3] == "F" && s2[3] == "D") {
			cout << "1";
			else {
				cout << "0";
			}
			if (s1[3] == 'A' && s2[3] == 'B' || s1[3] == 'B' && s2[3] == 'C' || s1[3] == 'B' && s2[3] == 'A' || s1[3] == 'C'
			        && s2[3] == 'B' || s1[3] == 'A' && s2[3] == 'B' || s1[3] == "D" && s2[3] == "F" || s1[3] == "F" && s2[3] == "D") {
				cout << "1";
				else {
					cout << "0";
				}
			}
		}
	}
}
return 0;
}