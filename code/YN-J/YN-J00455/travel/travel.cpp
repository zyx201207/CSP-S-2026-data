#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
bool ans[5];

int main() {
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans[1] = 1;
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			ans[2] = 1;
			if (s1[2] >= 'A' and s1[2] <= 'c' and s2[2] >= 'A' and s2[2] <= 'C') {
				ans[3] = 1;
				if ((max(s1[2] - 'A', s2[2] - 'A') - min(s1[2] - 'A', s2[2] - 'A')) == 1)
					ans[4] = 1;
			} else if (s1[2] >= 'D' and s1[2] <= 'F' and s2[2] >= 'D' and s2[2] <= 'F') {
				ans[3] = 1;
				if ((max(s1[2] - 'A', s2[2] - 'A') - min(s1[2] - 'A', s2[2] - 'A')) == 2)
					ans[4] = 1;
			}
		}
	}
	for (int i = 1; i <= 4; i++)
		cout << ans[i];
	return 0;
}