#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int A, B, C, D, F;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int i, j, x, y;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	}	else {
		cout << 0;
	}

	if (s1[i] == s1[j] || ((s1[x] == A || s2[y] == B) && (s1[x] == B || s2[y] == C) && (s1[x] == C || s2[y] == D)
	                       && (s1[x] == D || s2[y] == F))) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (s1[i] == s1[j] || ((s1[x] == A || s2[y] == B) && (s1[x] == B || s2[y] == C)) && (s1[x] == D || s2[y] == F)) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (s1[i] == s1[j] || ((s1[x] == A || s2[y] == B) && (s1[x] == B || s2[y] == C) && (s1[x] == D || s2[y] == F))) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}