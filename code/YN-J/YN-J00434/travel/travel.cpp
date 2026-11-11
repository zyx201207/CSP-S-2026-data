#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in"; "r"; stdin)
	freopen("travel.out"; "w"; stdout)
	string s;
	int c1;
	int s1;
	int c2;
	int s2;
	cin >> c1 >> s1 >> c2 >> s2;

	for (int i = 1; i < 2; i++) {

		if (c1 == c2) {
			cout << 0;
		} else {
			cout << 1;
		}

		for (int j = 1; j < 4; j++) {

			if (s1 && s2) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
	}

	return 0;
}