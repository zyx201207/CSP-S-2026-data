#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main () {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	long long cc1 = (s1[0] - '0') * 10 + (s1[1] - '0'),
			  cc2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (cc1 != cc2) {
		cout << "000";
		return 0;
	}
	cout << "1";
	long long ss1 = s1[2] - 'A' + 1,
			  ss2 = s2[2] - 'A' + 1;
	if (ss1 == 6)ss1 --;
	if (ss2 == 6)ss2 --;
	if ((ss1 <= 3 && ss2 <= 3) || (ss1 > 3 && ss2 > 3)) {
		cout << "1";
	}
	else {
		cout << "00";
		return 0;
	}
	if (abs (ss1 - ss2) <= 1)
		cout << "1";
	else 
		cout << "0";
	return 0;
}
