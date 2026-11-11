#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int class1, class2;
	string str1, str2;
	cin >> class1 >> str1 >> class2 >> str2;
	if (class1 == class2) {
		cout << "1";
		if (str1.substr(0, 2) == str2.substr(0, 2)) {
			cout << "1";
			if (str1[2] <= 'C' and str2[2] <= 'C') {
				cout << "1";
				if (abs(str1[2] - str2[2]) <= 1) {
					cout << "1";
					return 0;
				}
				else {
					cout << "0";
					return 0;
				}
			}
			else if (str1[2] >= 'D' and str2[2] >= 'D'){
				cout << "11";
				return 0;
			}
			else {
				cout << "00";
				return 0;
			}
		}
		else {
			cout << "000";
			return 0;
		}
	}
	else {
		cout << "0000";
		return 0;
	}
	return 0;
}
