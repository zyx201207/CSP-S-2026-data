#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	map<char, int>mp;
	mp['F'] = mp['D'] = 0;
	mp['C'] = mp['B'] = mp['A'] = 1;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char m1 = s1[2];
	char m2 = s2[2];
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && mp[m1] == mp[m2])
		cout << 1;
	else
		cout << 0;
	bool f1 = ((m1 == 'F' && m2 == 'D') || (m1 == 'D' && m2 == 'F'));
	bool f2 = ((m1 == 'C' && m2 == 'B') || (m1 == 'B' && m2 == 'C'));
	bool f3 = ((m1 == 'A' && m2 == 'B') || (m1 == 'B' && m2 == 'A'));
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && mp[m1] == mp[m2] && (f1 || f2 || f3))
		cout << 1;
	else
		cout << 0;
	return 0;
}
