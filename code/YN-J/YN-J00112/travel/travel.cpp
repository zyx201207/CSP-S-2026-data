#include <bits/stdc++.h>
using namespace std;
int n;
int c1, c2, cs1, cs2;
char s1, s2;

bool f(char c) {
	if (c == 'A' || c == 'B' || c == 'C')
		return 1;
	return 0;
}

bool b2() {
	if (s1 == 'C' && s2 == 'A')
		return 0;
	return 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> cs1 >> s1 >> c2 >> cs2 >> s2;
	cout << (c1 == c2);
	cout << (c1 == c2 && cs1 == cs2);
	cout << (c1 == c2 && cs1 == cs2 && f(s1) == f(s2));
	cout << (c1 == c2 && cs1 == cs2 && f(s1) == f(s2) && b2());
	return 0;
}