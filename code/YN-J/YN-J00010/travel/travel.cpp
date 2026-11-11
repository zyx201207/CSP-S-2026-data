#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;//车厢相同
	else
		cout << 0;
	if (s1[0] + s1[1] == s2[0] + s2[1]) { //排相同
		cout << 1;
	} else {
		cout << 0;
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			cout << 1;
		if (s1[2] == 'D' || s1[2] == 'F') {
			if (s2[2] == 'D' || s2[2] == 'F') {
				cout << 1;
			}
		}
	}//边相同
	if (s1[2] == 'A' && s2[2] == 'B') { //相邻
		cout << 1;
	}
	if (s1[2] == 'B' && s2[2] == 'A' || s2[2] == 'C') { //相邻
		cout << 1;
	}
	if (s1[2] == 'C' && s2[2] == 'B') { //相邻
		cout << 1;
	}
	if (s1[2] == 'D' && s2[2] == 'F' || s2[2] == 'D' && s1[2] == 'F') { //相邻
		cout << 1;
	}
	return 0;
}