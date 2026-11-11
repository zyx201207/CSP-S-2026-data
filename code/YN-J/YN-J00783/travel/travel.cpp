#include <bits/stdc++.h>

using namespace std;

int ans[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int c1, c2;
	char s1[5], s2[5];
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c1 && ((c1 != 01 && c1 != 16) && (c2 != 01 && c2 != 16))) {
		ans[1]
		    = 1;
	} else {
		ans[1] = 0;
	}
	if (s1 == s2) {
		ans[2]
		    = 1;
		ans[3] = 1;
	}
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		ans[2]
		    = 1;
	} else {
		ans[2] = 0;
	}
	if ((s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'C')) {
		ans[3]
		    = 1;
	}
	if ((s1[3] == 'B' && s2[3] == 'A')
	        || (s1[3] == 'C' && s2[3] == 'B')) {
		ans[3] = 1;
	}
	if ((s1[3] == 'D' && s2[3] == 'F')
	        || (s1[3] == 'F' && s2[3] == 'D')) {
		ans[3] = 1;
	} else {
		ans[3] = 0;
	}


	if (s1[3] == s2[3] - 32) {
		ans[4]
		    = 1;
	} else {
		ans[4] = 0;
	}
	for (int i = 1; i <= 4; i++) {
		cout << ans[i];
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}