#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;
using std::string;

#define int long long

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

string c1, c2, s1, s2;

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[2] > s2[2])
		std::swap(s1, s2);
	bool last = true;
	cout << ((last = (c1 == c2)) ? '1' : '0');
	cout << ((last &= (s1[0] == s2[0] && s1[1] == s2[1])) ? '1' : '0');
	cout << ((last &= ((s1[2] - 'A') / 3 == (s2[2] - 'A') / 3)) ? '1' : '0');
	bool flag1 = (s2[2] - s1[2] == 1);
	bool flag2 = (s1[2] == 'D' && s2[2] == 'F');
	cout << ((last &= (flag1 || flag2)) ? '1' : '0') << '\n';

	return 0;
}