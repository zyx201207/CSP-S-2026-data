#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1[3], s2[3];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 ;
	cin >> s1[3] >> s2[3];
	if (c1 == 16 || c1 == 01 || c2 == 16 || c2 == 01 || c1 > 17 || c2 > 17 )
		return 0;
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	if (s1[0] == s2[0] && s1[1] == s2[1])
		cout << 1;
	else
		cout << 0;
	if (s1[1] == s2[1])
		cout << 11;
	else if (s1[1] != s2[1])
		cout << 00;
	else if (s1[2] != s2[2])
		cout << 01;
	else
		cout << 10;
	return 0;
}