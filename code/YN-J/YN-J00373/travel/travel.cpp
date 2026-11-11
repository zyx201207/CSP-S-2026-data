#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1[22], s1[23], c2[22], s2[23];
	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= 18; j++) {
			if (c1[i] == c2[i]) {
				cout << "1";
			} else {
				cout << "0";
			}
			if (s1[j] == s2[j]) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
	}
	return 0;
}