#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "", p1, p2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		ans += "1";
		p1 = s1.substr(0, 2);
		p2 = s2.substr(0, 2);
		if (p1 != p2) {
			cout << ans << "000";
			return 0;
		} else {
			ans += "1";
			char w1 = s1[2], w2 = s2[2];
			int lr1, lr2;
			if (w1 == 'F')
				w1 = 'E';
			if (w2 == 'F')
				w2 = 'E';
			if (w1 == 'A' || w1 == 'B' || w1 == 'C')
				lr1 = 1;
			if (w2 == 'A' || w2 == 'B' || w2 == 'C')
				lr2 = 1;
			if (w1 == 'D' || w1 == 'E')
				lr1 = 0;
			if (w2 == 'D' || w2 == 'E')
				lr2 = 0;
			if (lr1 != lr2) {
				cout << ans << "00";
				return 0;
			} else {
				ans += "1";
				if (!((abs(w1 - w2) == 1) && !((w1 == 'C' && w2 == 'D') || (w2 == 'C' && w1 == 'D')))) {
					cout << ans << "0";
					return 0;
				} else
					ans += "1";
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

