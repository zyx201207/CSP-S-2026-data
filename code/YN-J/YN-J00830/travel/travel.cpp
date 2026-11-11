#include <bits/stdc++.h>
using namespace std;

int main() {
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	string s1, s2, s3, s4, str1 = "", str2 = "";
	char str3, str4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		flag1 = 1;
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		str1 += s2[i];
		str2 += s4[i];
	}
	str3 = s2[2];
	str4 = s4[2];
	if (str1 == str2) {
		flag2 = 1;
	} else {
		cout << "1000";
		return 0;
	}
	if (str3 < 'D' && str4 < 'D') {
		flag3 = 1;
	}
	if (str3 > 'C' && str4 > 'C') {
		flag3 = 1;
	}
	if (str3 == 'A' && str4 == 'B') {
		flag4 = 1;
	}
	if (str3 == 'B' && str4 == 'C') {
		flag4 = 1;
	}
	if (str3 == 'D' && str4 == 'E') {
		flag4 = 1;
	}
	if (str3 == 'B' && str4 == 'A') {
		flag4 = 1;
	}
	if (str3 == 'C' && str4 == 'B') {
		flag4 = 1;
	}
	if (str3 == 'E' && str4 == 'D') {
		flag4 = 1;
	}
	if (flag1 == 1 && flag2 == 1 && flag3 == 1) {
		cout << flag1 << flag2 << flag3 << flag4;
	} else {
		cout << flag1 << flag2 << flag3 << flag4;
	}
	return 0;
}