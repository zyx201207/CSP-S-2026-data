#include <bits/stdc++.h>
using namespace std;
int a[6][20];
int a1, a2;
char s1[4], s2[4];
char ans[10];
int t1 = 0, t2 = 0;
int x1, x2, y10, y2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> s1 >> a2 >> s2;
	if (a1 == a2) {
		ans[0] = '1';
	} else {
		cout << "0000";
		return 0;
	}
	t1 += (s1[1] - '0') * 1;
	t1 += (s1[0] - '0') * 10;
	t2 += (s2[1] - '0') * 1;
	t2 += (s2[0] - '0') * 10;
	if (t1 == t2) {
		ans[1] = '1';
	} else {
		ans[1] = '0';
	}
	if (s1[2] == 'A')
		x1 = 1;
	if (s1[2] == 'B')
		x1 = 2;
	if (s1[2] == 'C')
		x1 = 3;
	if (s1[2] == 'D')
		x1 = 4;
	if (s1[2] == 'F')
		x1 = 5;
	y10 = t1;
	if (s2[2] == 'A')
		x2 = 1;
	if (s2[2] == 'B')
		x2 = 2;
	if (s2[2] == 'C')
		x2 = 3;
	if (s2[2] == 'D')
		x2 = 4;
	if (s2[2] == 'F')
		x2 = 5;
	y2 = t2;
	if ((x1 <= 3 && x2 <= 3) || (x1 > 3 && x2 > 3)) {
		if (y10 == y2) {
			ans[2] = '1';
		} else {
			ans[2] = '0';
		}
	} else {
		ans[2] = '0';
		ans[3] = '0';
	}
	if ((x1 + 1 == x2 && y10 == y2) || (x1 - 1 == x2 && y10 == y2) || (y10 + 1 == y2 && x1 == x2) || (y10 - 1 == y2
	        && x1 == x2)) {
		if (ans[3] == '0') {
			ans[3] = '0';
		} else {
			ans[3] = '1';
		}
	} else {
		ans[3] = '0';
	}
	for (int i = 0; i < 4; i++) {
		cout << ans[i];
	}
	return 0;
}
