#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin)
	freopen("travel.out", "w", stdout)
	int a, b, i, j, A, B, C, D, F, c1,  s1 = a + i, c2, s2 = b + j;
	cin >> c1, s1, c2, s2;

	if (c1 = c2) {
		cout << 0;
	} else {
		cout << 1;
	}

	if (a = b) {
		cout << 0;
	} else {
		cout << 1;
	}

	if ((i == A || B || C) && (j == A || B || C) || ( i == D || F ) && (j == D || F)) {
		cout << 1;
	} else {
		cout << 0;
	}

	if ((i == A && j == B) || (i == B && j == C) || (i == D && j == F) || (j == A && i == B) || (j == B && i == C)
	        || (j == D && i == F)) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
