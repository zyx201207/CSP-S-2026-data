#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string rc, rn, xc, xn;
	cin >> rc >> rn >> xc >> xn;
	if (rc == xc) {
		printf("1");
		if (rn[0] == xn[0] && rn[1] == xn[1]) {
			printf("1");
			// ABC DF
			if (rn[2] >= 'A' && rn[2] <= 'C' && xn[2] >= 'A' && xn[2] <= 'C') {
				printf("1");
				if (rn[2] + 1 == xn[2] || xn[2] + 1 == rn[2]) {
					printf("1\n");
				} else {
					printf("0\n");
				}
			} else if ((rn[2] == 'D' || rn[2] == 'F') && (xn[2] == 'D' || xn[2] == 'F')) {
				printf("1");
				if (rn[2] + 2 == xn[2] || xn[2] + 2 == rn[2]) {
					printf("1\n");
				} else {
					printf("0\n");
				}
			} else {
				printf("00\n");
			}
		} else {
			printf("000\n");
		}
	} else {
		printf("0000\n");
	}
	
	return 0;
}
