#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[2] == 'F') s1[2] = 'E';
	if (s2[2] == 'F') s2[2] = 'E';
	if (c1 != c2) cout << "0000\n";
	else if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000\n";
	else if ((s1[2] <= 'C') != (s2[2] <= 'C')) cout << "1100\n";
	else if (abs(s2[2] - s1[2]) > 1) cout << "1110\n";
	else cout << "1111\n";
	return 0;
}
