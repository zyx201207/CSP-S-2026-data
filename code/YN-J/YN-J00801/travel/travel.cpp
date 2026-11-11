#include <bits/stdc++.h>
using namespace std;
int a, b, f;
string s, s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> s >> b >> s1;
	if (a != b) {
		cout << "0000";
		return 0;
	} else if (s[0] != s1[0] || s1[1] != s[1]) {
		cout << "1000";
		return 0;
	} else if ((s[2] == 'C' && s1[2] == 'D') | (s[2] == 'D' && s1[2] == 'C')) {
		cout << "1100";
		return 0;
	} else if ((s[2] == 'C' && s1[2] == 'A') | (s[2] == 'A' && s1[2] == 'C')) {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
}