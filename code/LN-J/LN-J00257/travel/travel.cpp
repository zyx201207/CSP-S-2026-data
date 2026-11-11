#include <bits/stdc++.h>
using namespace std;

map<char, bool> mp = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 1}, {'F', 1}};
int l1, l2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> l1 >> s1 >> l2 >> s2;
	if (l1 == l2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if (mp[s1[2]] == mp[s2[2]]) {
				cout << "1";
				if (s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
