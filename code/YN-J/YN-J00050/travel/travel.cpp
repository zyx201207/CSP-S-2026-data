#include <bits/stdc++.h>
using namespace std;

int main() {
	char c1[2], s1[3], c2[2], s2[3];
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i <= 1; i++) {
		if (c1[i] == c2[i]) {
			q1 = 1;
		} else {
			q1 = 0;
			cout << q1 << q2 << q3 << q4;
			return 0;
		}
	}
	for (int i = 0; i <= 1; i++) {
		if (s1[i] == s2[i]) {
			q2 = 1;
		} else {
			q2 = 0;
			cout << q1 << q2 << q3 << q4;
			return 0;
		}
	}
	if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
		q3 = 1;
	} else {
		cout << q1 << q2 << q3 << q4;
		return 0;
	}
	if (abs(s1[2] - s2[2]) == 1) {
		q4 = 1;
	} else {
		cout << q1 << q2 << q3 << q4;
		return 0;
	}
	cout << q1 << q2 << q3 << q4;
	return 0;
}