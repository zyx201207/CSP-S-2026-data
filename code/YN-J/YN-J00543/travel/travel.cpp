#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a = 0, b = 0, c = 0, d = 0;
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}

	for (int i = 0; i < s1.length() - 1; i++) {

		if (s1[i] == s2[i]) {
			a++;
		}
	}

	if ((a == 2) and (c1 == c2)) {
		c++;
		cout << 1;
	} else {
		cout << 0;
	}

	if ((((s1[2] <= 'C') and (s2[2] <= 'C')) or ((s1[2] <= 'F') and (s1[2] >= 'D')) and ((s2[2] <= 'F') and (s2[2] >= 'D')))
	        and (c == 1)) {
		cout << 1;
		b++;
	} else {
		cout << 0;
	}



	if (((s1[2] + 1 == s2[2]) or (s2[2] + 1 == s1[2])) and (b == 1)) {
		cout << 1;
	} else {
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}