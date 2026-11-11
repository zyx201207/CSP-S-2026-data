#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[4];
	char a1[3], a2[3];
	int num1, num2;
	if (c1 == c2) {
		ans[0] = 1;
	} else {
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 0;
		ans[3] = 0;
		for (int i = 0; i <= 3; i++) {
			cout << ans[i];
		}
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		a1[i] = s1[i];
	}
	for (int i = 0; i < 3; i++) {
		a2[i] = s2[i];
	}


	if ((a1[0] == a2[0]) && (a1[1] == a2[1])) {
		ans[1] = 1;
	} else {
		ans[1] = 0;
		ans[2] = 0;
		ans[3] = 0;
		for (int i = 0; i <= 3; i++) {
			cout << ans[i];
		}
		return 0;
	}


	if (a1[2] == 'A') {
		num1 = 65;
	} else if (a1[2] == 'B') {
		num1 = 66;
	} else if (a1[2] == 'C') {
		num1 = 67;
	} else if (a1[2] == 'D') {
		num1 = 68;
	} else if (a1[2] == 'F') {
		num1 = 70;
	}
	if (a2[2] == 'A') {
		num2 = 65;
	} else if (a2[2] == 'B') {
		num2 = 66;
	} else if (a2[2] == 'C') {
		num2 = 67;
	} else if (a2[2] == 'D') {
		num2 = 68;
	} else if (a2[2] == 'F') {
		num2 = 70;
	}
	if ((num1 + num2 <= 133) || (num1 + num2 == 138)) {
		ans[2] = 1;
	} else {
		ans[2] = 0;
	}
	if ((num1 == 68) || (num2 == 68)) {
		ans[2] = 0;
	}
	if ((ans[0] == 1) && (ans[1] == 1) && (ans[2] == 1)) {
		if ((num1 + 1 == num2)
		        || (num1 - 1 == num2))  {
			ans[3]
			    = 1;
		} else if (num1 + num2 == 138) {
			ans[3] = 1;
		} else {
			ans[3] = 0;
		}
	} else {
		ans[3] = 0;
	}
	for (int i = 0; i <= 3; i++) {
		cout << ans[i];
	}
	return 0;
}