#include <bits/stdc++.h>
using namespace std;
int a[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> c1 >> s1 >> c2 >> s2;
//	for (int i = 1; i <= 4; i++) {
	int x = stoi(c1), y = stoi(c2);
	if (x != y) {
		cout << "0000";
		return 0;
	}
	string s = "", t = "";
	for (int j = 0; j < 2; j++) {
		s += s1[j];
		t += s2[j];
	}
	x = stoi(s), y = stoi(t);
	if (x != y) {
		cout << "1000";
		return 0;
	}
	string ss = "";
	if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') {
		ss = "111";
	} else if (s1[2] == 'D' || s1[2] == 'F' && s2[2] == 'D' || s2[2] == 'F') {
		ss = "111";
	} else {
		cout << "1100";
		return 0;
	}
	if (abs(s1[2] - s2[2]) == 1) {
		cout << "1111";
	} else
		cout << "1110";
//	}
	return 0;
}