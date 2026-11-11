#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 0;

	if (c1 != c2)
		ans1 = 0;
	if (ans1 == 1)
	{
		if ((s1[0] != s2[0]) || (s1[1] != s2[1]))
			ans2 = 0;
	}
	if (ans2 == 1) {
		if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'F'))
			ans3 = 0;
		if ((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (s1[2] == 'D' || s1[2] == 'F'))
			ans3 = 0;
	}
	if (ans3 == 1) {
		if (!((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C')
		        || (s1[2] == 'C' && s2[2] == 'B')) || (s1[2] == 'D' || s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
			ans4 == 1;
	}
	if (ans1 == 0) {
		ans2 = 0;
		ans3 = 0;
		ans4 = 0;
	}
	if (ans2 == 0) {
		ans3 = 0;
		ans4 = 0;
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}