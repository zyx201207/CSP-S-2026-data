#include <bits/stdc++.h>
#include <iostream>
using namespace std;
char s1[101], s2[101];

int main() {
	freopen(const_char, "w", travel.in);
	freopen(const_char, "r", travel.out);
	int c1, c2;
	int m, n, a;
	cin >> c1;
	for (int i = 1; i <= 3; i++) {
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 1; i <= 3; i++) {
		cin >> s2[i];
	}
	//第一个问题
	if (c1 == c2) {
		m = 1;
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		//第二个问题
		if (s1[2] == s2[2]) {
			n = 1;
		} else {
			cout << "1000";
			return 0;
		}
		//第三个问题
		if (s1[3] == 65 || s1[3] == 66 || s1[3] == 67) {
			if (s2[3] == 65 || s2[3] == 66 || s2[3] == 67) {
				a = 1;
			} else {
				cout << "1100";
				return 0;
			}
		} else if (s1[3] == 68 || s1[3] == 69) {
			if (s2[3] == 68 || s2[3] == 69) {
				a = 1;
			} else {
				cout << "1100";
				return 0;
			}
		}
		//第四个问题
		if (s1[3] == 65) {
			if (s2[3] == 66) {
				cout << "1111";
				break;
			} else {
				cout << "1110";
				break;
			}
		} else if (s1[3] == 66) {
			if (s2[3] == 65 || s2[3] == 67) {
				cout << "1111";
				break;
			} else {
				cout << "1110";
				break;
			}
		} else if (s1[3] == 67) {
			if (s2[3] == 66) {
				cout << "1111";
				break;
			} else {
				cout << "1110";
				break;
			}
		} else if (s1[3] == 68) {
			if (s2[3] == 69) {
				cout << "1111";
				break;
			} else {
				cout << "1110";
				break;
			}
		} else if (s1[3] == 69) {
			if (s2[3] == 68) {
				cout << "1111";
				break;
			} else {
				cout << "1110";
				break;
			}
		}
	}
	return 0;
}