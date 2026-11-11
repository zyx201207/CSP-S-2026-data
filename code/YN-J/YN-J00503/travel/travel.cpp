#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "11";
	} else {
		cout << "00";
	}
	if (s1 == s2) {
		cout << "11";
	} else if (s1 != s2) {
		cout << "11" || "10";
	}
	return 0;
}