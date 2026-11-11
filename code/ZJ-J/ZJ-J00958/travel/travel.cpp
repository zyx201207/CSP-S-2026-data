#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int ans1 = c1 == c2 ? 1 : 0;
	int ans2 = ans1 && s1[0] == s2[0] && s1[1] == s2[1] ? 1 : 0;
	int d1 = s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' ? 1 : 0;
	int d2 = s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C' ? 1 : 0;
	int ans3 = ans2 && d1 == d2 ? 1 : 0, ans4 = 0;
	if (ans1 && ans2 && ans3) {
		if (d1 == 0) ans4 = 1;
		else if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) ans4 = 1;
	}
	return cout << ans1 << ans2 << ans3 << ans4, 0;
}

