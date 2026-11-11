#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	string c1, s1, c2, s2;
	int f = 0, f1 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}


	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
			cout << 1;
			f = 1;
		} else
			cout << 0;
	} else
		cout << 0 << 0;
	if (f == 1) {
		if (s1[2] + 1 == s2[2] || s1[1] - 1 == s2[2])
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}
