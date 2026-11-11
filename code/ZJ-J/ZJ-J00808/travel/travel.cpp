#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
bool flag = 1;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (flag) if (c1 != c2) flag = 0;
	cout << flag;
	
	if (flag) if (s1[0] != s2[0] || s1[1] != s2[1]) flag = 0;
	cout << flag;
	
	if (flag) if (s1[2] <= 'C' && s2[2] >= 'D' || s1[2] >= 'D' && s2[2] <= 'C') flag = 0;
	cout << flag;
	
	if (flag) if (s2[2] != s1[2] + 1 && s2[2] != s1[2] - 1) flag = 0;
	cout << flag;
	
	cout << '\n';
	return 0;
}
