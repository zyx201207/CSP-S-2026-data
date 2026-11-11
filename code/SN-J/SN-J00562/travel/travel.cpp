#include <bits/stdc++.h>
#define int long long
using namespace std;
bool is_right (char a, char b) {
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') return true;
	else if (a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F') return true;
	return false;
}
signed main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	char seat1, seat2;
	int a1, b1, a2, b2;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = stoi(c1), b1 = stoi(s1.substr(0, 2)), 
	a2 = stoi(c2), b2 = stoi(s2.substr(0, 2));
	seat1 = s1[2], seat2 = s2[2];
	if (a1 != a2) cout << "0000";
	else if (b1 != b2) cout << "1000";
	else if (is_right(seat1, seat2) == false) cout << "1100";
	else if (abs(seat1 - seat2) != 1) cout << "1110";
	else cout << "1111";
	return 0;
}
