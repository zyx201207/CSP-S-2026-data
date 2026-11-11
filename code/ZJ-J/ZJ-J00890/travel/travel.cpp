#include <bits/stdc++.h>
using namespace std;
string c, s, cc, ss;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> s >> cc >> ss;
	if (s[2] > ss[2])
		swap(s, ss);
	cout << int(c == cc) << int(c == cc && s.substr(0, 2) == ss.substr(0, 2)) << int(c == cc && s.substr(0, 2) == ss.substr(0, 2) && (s[2] == 'A' && ss[2] == 'B' || s[2] == 'A' && ss[2] == 'C' || s[2] == 'B' && ss[2] == 'C' || s[2] == 'D' && ss[2] == 'F')) << int(c == cc && s.substr(0, 2) == ss.substr(0, 2) && (s[2] == 'A' && ss[2] == 'B' || s[2] == 'B' && ss[2] == 'C' || s[2] == 'D' && ss[2] == 'F'));
}