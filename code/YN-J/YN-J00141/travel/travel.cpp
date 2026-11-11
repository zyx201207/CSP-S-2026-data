#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int x = 0;
	if (c1 == c2) {
		cout << 1;
		x++;
	} else {
		cout << 0;
		x = 0;
	}
	int s = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j] && s1[i + 1] == s2[j + 1] && s1.end() != s2.end()) {
				s++;
			} else {
				s = 0;
			}
		}
	}
	int c = 0;
	int d = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			for (int k = 'A'; k <= 'C'; k++) {
				for (int l = 'D'; l <= 'F'; l++) {
					if (s1[i] != k && s2[j] == k || s1[i] != k && s2[j] != k || s1[i] == k && s2[j] != k || s1[i] == l && s2[j] == k
					        || s1[i] == k && s2[j] == l) {
						c = 0;
					} else {
						c++;
					}
					if (s1[i] != l && s2[j] == l || s1[i] != l && s2[j] != l || s1[i] == l && s2[j] != l || s1[i] == k && s2[j] == k) {
						d = 0;
					} else {
						d++;
					}
				}

			}
		}
	}
	int y = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			for (int k = 'A'; k <= 'F'; k++) {
				if (s1[i - 1] == s2[j] || s1[i] == s2[j - 1]) {
					y++;
				} else {
					y = 0;
				}
			}
		}

	}

	if (s != 0 && x != 0) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (c != 0 && x != 0 || d != 0 && x != 0) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (y != 0 && x != 0) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}