#include <bits/stdc++.h>
using namespace std;
int nm[10];
int zuo[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a, b, aa, bb;
	cin >> a >> b >> aa >> bb;
	if (a == aa) {
		nm[1] = 1;
		bool flag = 1;
		for (int i = 0; i < 2; i++) {
			if (b[i] != bb[i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			nm[2] = 1;
			char eb, ebb;
			eb = b[2];
			ebb = bb[2];
			zuo[eb - 'A' + 1]++;
			zuo[ebb - 'A' + 1]++;
			int nn = zuo[1] + zuo[2] + zuo[3];
			int mm = zuo[4] + zuo[5];
			if (nn == 2 || mm == 2) {
				nm[3] = 1;
				if (zuo[1] == 1 && zuo[2] == 1 || zuo[3] == 1 && zuo[2] == 1 || zuo[4] == 1 && zuo[5] == 1) {
					nm[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << nm[i];
	}


	return 0;
}
