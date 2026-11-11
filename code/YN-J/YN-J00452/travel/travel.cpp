#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, res;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	res = "0000";
	if (c1 == c2)
		res[0] = '1';
	if (res[0] == '1' && s1[0] == s2[0] && s1[1] == s2[1])
		res[1] = '1';
	if (res[1] == '1' && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')))
		res[2] = '1';
	if (res[2] == '1' && abs(s1[2] - s2[2]) == 1)
		res[3] = '1';
	cout << res;
	return 0;
}