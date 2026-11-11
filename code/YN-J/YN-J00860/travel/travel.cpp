#include <bits/stdc++.h>
using namespace std;


int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int ans[4] = {0};
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	int t1 = int(s1[2] - '0');
	int t2 = int(s2[2] - '0');
	int q = abs(t1 - t2);
	if (c1 == c2) {
		ans[0] = 1;

		if (s1[0] == s2[0]) {
			if (s1[1] == s2[1]) {
				ans[1] = 1;
				if (t1 > 19 && t2 > 19) {
					ans[2] = 1;
					ans[3] = 1;
				} else {
					if ( t1 < 20 && t2 < 20) {
						ans[2] = 1;
						if (q == 1) {
							ans[3] = 1;
						}
					}

				}



			}

		}
	}
	for (int i = 0; i < 4; i++) {
		cout << ans[i];
	}


	return 0;
}