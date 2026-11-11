#include <bits/stdc++.h>
using namespace std;
long long int c1,c2;
string s1,s2;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	else {
		cout << "1";
	}
	if (s1[1 - 1] == s2[1 - 1] && s1[2 - 1] == s2[2 - 1]) {
		cout << "1";
	}
	else {
		cout << "000";
		return 0;
	}
	if ((s1[3 - 1] >= 'A' && s1[3 - 1] <= 'C' && s2[3 - 1] >= 'A' && s2[3 - 1] <= 'C') || (s1[3 - 1] >= 'D' && s1[3 - 1] <= 'F' && s2[3 - 1] >= 'D' && s2[3 - 1] <= 'F')) {
		cout << "1";
	}
	else {
		cout << "00";
		return 0;
	}
	if (abs(s1[3 - 1] - s2[3 - 1]) == 1) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}
