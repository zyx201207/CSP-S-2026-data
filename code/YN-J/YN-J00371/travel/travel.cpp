#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, sit1, sit2;
	string b1, b2;
	bool ans[4] = {};
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 == a2) {
		ans[0] = 1;
		if (b1[0] == b2[0] && b1[1] == b2[1]) {
			ans[1] = 1;
			switch (b1[2]) {
				case 'A' :
					sit1 = 1;
					break;
				case 'B' :
					sit1 = 2;
					break;
				case 'C' :
					sit1 = 3;
					break;
				case 'D' :
					sit1 = 5;
					break;
				case 'F' :
					sit1 = 6;
					break;
			}
			switch (b2[2]) {
				case 'A' :
					sit2 = 1;
					break;
				case 'B' :
					sit2 = 2;
					break;
				case 'C' :
					sit2 = 3;
					break;
				case 'D' :
					sit2 = 5;
					break;
				case 'F' :
					sit2 = 6;
					break;
			}
			if ((sit1 < 4 && sit2 < 4) || (sit1 > 4 && sit2 > 4)) {
				ans[2] = 1;
				if (sit1 - sit2 == 1 || sit2 - sit1 == 1) {
					ans[3] = 1;
				}
			}
		}
	}
	cout << ans[0] << ans[1] << ans[2] << ans[3];
	return 0;
}