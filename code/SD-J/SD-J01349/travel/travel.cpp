#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	string ans = "0000";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans[0] = '1';
		if (s1.substr(0, 2) == s2.substr(0, 2)) {
			ans[1] = '1';
			char a = s1[2], b = s2[2];
			if (a > b) swap(a, b);
			if ((a == 'A' && b == 'B') || (a == 'A' && b == 'C') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) {
				ans[2] = '1';
			}
			if (abs((int)(a) - (int)(b)) == 1 && a != 'C' && b != 'D') {
				ans[3] = '1';
			}
		}
	}
	cout << ans;
	return 0;
}

