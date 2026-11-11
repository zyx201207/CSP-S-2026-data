#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string rc;
	string rz;
	string xc;
	string xz;
	string flag;
	cin >> rc >> rz >> xc >> xz;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	if (rc == xc) {
		flag[1] = 1;
		if (rz[0] == xz[0] && rz[1] == xz[1]) {
			flag[2] = 1;
			if ((rz[2] == 'A' && xz[2] == 'B') || (rz[2] == 'A' && xz[2] == 'C') || (rz[2] == 'B' && xz[2] == 'A') || (rz[2] == 'B'
			        && xz[2] == 'C') || (rz[2] == 'C' && xz[2] == 'A') || (rz[2] == 'C' && xz[2] == 'B') || (rz[2] == 'D' && xz[2] == 'F')
			        || (rz[2] == 'F' && xz[2] == 'D')) {
				flag[3] = 1;
				if ((rz[2] == 'A' && xz[2] == 'B') || (rz[2] == 'B' && xz[2] == 'A') || (rz[2] == 'B' && xz[2] == 'C') || (rz[2] == 'C'
				        && xz[2] == 'B') || (rz[2] == 'D' && xz[2] == 'F') || (rz[2] == 'F' && xz[2] == 'D')) {
					flag[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (flag[i] != 1) {
			cout << "0";
		} else if (flag[i] == 1) {
			cout << "1";
		}
	}


	return 0;
}