#include <bits/stdc++.h>
using namespace std;
char s1, s2, c1, c2;
int  q, e;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		q = 1;
	} else {
		q = 0;
	}
	if (s1 > s2 || s1 < s2) {
		e = 0;
	}
	cout << q << e << 0 << 0;
	fclose(stdout);
	return 0;
}