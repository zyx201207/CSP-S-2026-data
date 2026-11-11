#include <bits/stdc++.h>
using namespace std;
bool flag, flbg, flcg, fldg;
char c1[5], c2[5], s1[5], s2[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> c1[i];
	}
	for (int i = 1; i <= 3; i++) {
		cin >> s1[i];
	}
	for (int i = 1; i <= 2; i++) {
		cin >> c2[i];
	}
	for (int i = 1; i <= 3; i++) {
		cin >> s2[i];
	}
	for (int i = 1; i <= 3; i++) {
		if (c1[i] != c2[i]) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 1; i <= 2; i++) {
		if (s1[i] != s2[i]) {
			flbg = 1;
		}
	}
	if (flbg == 0) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (s1[3] <= 'C' && s2[3] <= 'C' || s1[3] > 'C' && s2[3] > 'C') {
		flcg = 1;
	}
	if (flcg == 1) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (int(s2[3] - s1[3]) == 1  || int(s1[3] - s2[3]) == 1 ) {
		fldg = 1;
	}
	if (fldg == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}