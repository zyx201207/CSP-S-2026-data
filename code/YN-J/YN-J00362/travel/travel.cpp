#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int c1, c2;
int  f1, f2, l;
int f3 = 1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d", &c1);
	cin >> s1;
	scanf("%d", &c2);
	cin >> s2;
	if (c1 == c2) {
		l = 1;
		printf("1");
	} else {
		printf("0");
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
	} else {
		f1 = 1;
	}
	if (s1[2] >= 'D' && s2[2] >= 'D') {
	} else if (s1[2] <= 'C' && s2[2] <= 'C') {
	} else {
		f2 = 1;
	}
	f3 = abs(s2[2] - s1[2]);
	if (f3 == 1) {
		f3 == 1;
	} else {
		f3 = 0;
	}
	if (!f1 && l) {
		printf("1");
	} else {
		printf("0");
	}
	if (!f2 && l && !f1 ) {
		printf("1");
	} else {
		printf("0");
	}
	if (!f2 && l && !f1) {
		printf("%d", f3);
	} else {
		printf("0");
	}
	return 0;
}