#include <bits/stdc++.h>
using namespace std;
int a[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f = 0;
	if (c1 == c2) {
		a[0] = 1;
		f++;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1] && f == 1) {
		a[1] = 1;
		f++;
	}
	if ((f == 2) && (((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] == 'D' && s2[2] == 'F')
	                 || (s1[2] == 'F' && s1[2] == 'D')))) {
		a[2] = 1;
		f++;
	}
	if (abs(s1[2] - s2[2]) == 1 && f == 3) {
		a[3] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		cout << a[i];
	}
	return 0;
}