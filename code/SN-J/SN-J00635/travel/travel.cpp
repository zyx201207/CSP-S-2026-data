//梁伯温 西安辅轮中学 SN-J00635
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;

string cr, cx, sr, sx;

int see(char ch) {
	if (ch == 65) return 1;
	if (ch == 66) return 2;
	if (ch == 67) return 3;
	if (ch == 68) return 4;
	if (ch == 70) return 5;
}

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> cr >> sr >> cx >> sx;
	char zmr = see(sr[2]);
	char zmx = see(sx[2]);
	if (cr != "01" && cr != "16" && cr == cx) {
		cout << "1";
		if (sr[0] == sx[0] && sr[1] == sx[1]) {
			cout << "1";
			if ((zmr <= 3 && zmx <= 3) || (zmr > 3 && zmx > 3)) {
				cout << "1";
				if (abs(zmr - zmx) == 1) {
					cout << "1";
				} else {
					cout <<"0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out ", "w", stdout);
	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

/*

02 01A 02 01B 1111
02 01C 02 01A 1110
02 01C 02 01F 1100

*/