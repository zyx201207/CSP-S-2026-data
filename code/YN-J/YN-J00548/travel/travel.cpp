#include <iostream>
using namespace std;


int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2;// s1[0]s1[1]s1[2]
	int c1, c2;
	cin >> c1 >> s1 >> c2 >> s2;
	while (c1 > 01 && c1 < 17 && c2 > 01 && c2 < 17) {
		if (c1 == c2) {
			cout << "1";
		} else {
			cout << "0";
		}
		break;
	}
	for (int i = 0; i <= 18; i++) {
		if (c1 == c2) {
			if (s1[0] == s2[0]) {
				if (s1[1] == s2[1]) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
			break;
		} else {
			cout << "0";
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (s1[0] == s2[0]) {
			if (s1[1] == s2[1]) {
				if (s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A') {
					if (s1[2] == 'A') {
						if (s2[2] == 'A' + 1 || s2[2] == 'A' + 2) {
							cout << "1";
						} else {
							cout << "0";
						}
					} else if (s1[2] == 'B') {
						if (s2[2] == 'B' - 1 || s2[2] == 'B' + 1) {
							cout << "1";
						} else {
							cout << "0";
						}
					} else if (s1[2] == 'C') {
						if (s2[2] == 'C' - 1 || s2[2] == 'C' - 2) {
							cout << "1";
						} else {
							cout << "0";
						}
					}
				} else if (s1[2] == 'D' || s1[2] == 'F' && s2[2] == 'D' || s2[2] == 'F') {
					if (s1[2] == 'D') {
						if (s2[2] == 'D' + 2) {
							cout << "1";
						} else {
							cout << "0";
						}
					} else if (s1[2] == 'F') {
						if (s2[2] == 'F' - 2) {
							cout << "1";
						} else {
							cout << "0";
						}
					}
				} else if (s1[2] == 'C') {
					if (s2[2] == 'C' + 1) {
						cout << "0";
					}
				}
				break;
			} else {
				cout << "0";
				break;
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (s1[0] == s2[0]) {
			if (s1[1] == s2[1]) {
				if (s1[2] == 'A') {
					if (s2[2] == 'A' + 1) {
						cout << "1";
					} else {
						cout << "0";
					}
				} else if (s1[2] == 'B') {
					if (s2[2] == 'B' + 1 || s2[2] == 'B' - 1) {
						cout << "1";
					} else {
						cout << "0";
					}
				} else if (s1[2] == 'C') {
					if (s2[2] == 'C' - 1) {
						cout << "1";
					} else {
						cout << "0";
					}
				} else if (s1[2] == 'D') {
					if (s2[2] == 'D' + 2) {
						cout << "1";
					} else {
						cout << "0";
					}
				}
			} else {
				cout << "0";
				break;
			}
		}
		break;
	}
	return 0;
}