#include<bits/stdc++.h>
using namespace std;

int get(char c) {
	if(c == 'A') return 0;
	if(c == 'B') return 1;
	if(c == 'C') return 2;
	if(c == 'D') return 3;
	return 4;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	bool ans1 = false, ans2 = false, ans3 = false, ans4 = false;
	if(c1 == c2) {
		ans1 = true;
		string x1 = s1.substr(0, 2), x2 = s2.substr(0, 2);
		if(x1 == x2) {
			ans2 = true;
			char seat1 = s1[s1.length() - 1], seat2 = s2[s2.length() - 1];
			bool l1 = (seat1 >= 'A' && seat1 <= 'C'), r1 = (seat1 == 'D' || seat1 == 'F'), l2 = (seat2 >= 'A' && seat2 <= 'C'), r2 = (seat2 == 'D' || seat2 == 'F');
			if((l1 && l2) || (r1 && r2)) {
				ans3 = true;
				int idx1 = get(seat1), idx2 = get(seat2);
				if(abs(idx1 - idx2) == 1) ans4 = true;
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
