#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool flg = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < 2; i++) {
		if (c1[i] != c2[i]) flg = 0;
	}
	if (flg) {
		for (int i = 0; i < 2; i++) {
			if (s1[i] != s2[i]) flg = 0;
		}
		if (flg) {
			if (((s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1) && (s1[2] + 1 != 'D' && s2[2] + 1 != 'D')) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) cout << "1111\n";
			else if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') cout << "1110\n";
			else cout << "1100\n";
			return 0;
		}
		cout << "1000\n";
		return 0;
	}
	cout << "0000\n";
	return 0;																																																																																		
} 
