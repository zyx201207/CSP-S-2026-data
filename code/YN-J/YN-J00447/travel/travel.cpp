#include <bits/stdc++.h>
using namespace std;
char c1[3], c2[3];
char s1[4], s2[4];
int d[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	fill(d + 1, d + 1 + 5, 1);
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
	for (int i = 1; i <= 2; i++) {
		if (c1[i] != c2[i]) {
			d[1] = 0;//1
		}
	}
	for (int i = 1; i <= 3; i++) {
		if (i < 3) {
			if (s1[i] == s2[i] && d[1] == 1) {
				d[2] = 1;//2
			} else {
				d[2] = 0;
			}
		} else {
			if (!((s1[i] >= 'A' && s1[i] <= 'C' && s2[i] >= 'A' && s2[i] <= 'C') || (s1[i] == 'D' && s2[i] == 'F' || s2[i] == 'D'
			        && s1[i] == 'F') && d[1] == 1 && d[2] == 1)) {
				d[3] = 0;//3
			} else {
				d[3] = 1;
			}
			if (!(s1[i] + 1 == s2[i] && (s1[i] != 'C' && s2[i] != 'D' || s1[i] != 'D' && s2[i] != 'C') && d[1] == 1 && d[2] == 1
			        && d[3] == 1)) {
				d[4] = 0;//4
			} else {
				if (s1[i] == 'C' && s2[i] == 'D' || s1[i] == 'D' && s2[i] == 'C' && d[1] == 1 ) {
					d[4] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << d[i];
	}

	return 0;
}
