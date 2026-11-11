#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string s1, s2;
	queue<int> n;
	cin >> a >> s1 >> b >> s2;
	if (a == b) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (s1[2] == 'A' && s2[2] == 'B') {
		cout << 1;
	} else if (s1[2] == 'A' && s2[2] == 'C') {
		cout << 1;
	} else if (s1[2] == 'B' && s2[2] == 'A') {
		cout << 1;
	} else if (s1[2] == 'B' && s2[2] == 'C') {
		cout << 1;
	} else if (s1[2] == 'C' && s2[2] == 'B') {
		cout << 1;
	} else if (s1[2] == 'C' && s2[2] == 'A') {
		cout << 1;
	} else if (s1[2] == 'D' && s2[2] == 'E') {
		cout << 1;
	} else if (s1[2] == 'E' && s2[2] == 'D') {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		return 0;
	}
	if (s1[2] == 'A' && s2[2] == 'B') {
		cout << 1;
	} else if (s1[2] == 'B' && s2[2] == 'A') {
		cout << 1;
	} else if (s1[2] == 'B' && s2[2] == 'C') {
		cout << 1;
	} else if (s1[2] == 'C' && s2[2] == 'B') {
		cout << 1;
	} else if (s1[2] == 'D' && s2[2] == 'E') {
		cout << 1;
	} else if (s1[2] == 'E' && s2[2] == 'D') {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}