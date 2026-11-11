//王子腾  SN-J00702  西安铁一中学 
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

string c_1 , s_1 , c_2 , s_2;
ll rp , xp;
char rz , xz;

int main () {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	rp = (s_1[0] - '0') * 10 + (s_1[1] - '0') * 1;
	xp = (s_2[0] - '0') * 10 + (s_2[1] - '0') * 1;
//	cout << rp << "  " << xp << "\n";
	rz = s_1[2];
	xz = s_2[2];
	if (c_1 != c_2) {
		cout << "0000" << "\n";
		return 0;
	}
	if (rp != xp) {
		cout << "1000" << "\n";
		return 0;
	}
	if (!((rz <= 'C' && xz <= 'C') || (rz >= 'D' && xz >= 'D'))) {
		cout << "1100" << "\n";
		return 0;
	}
	if (rz == 'A') {
		if (xz != 'B') {
			cout << "1110" << "\n";
			return 0;
		}
	}
	if (rz == 'B') {
		if ((xz != 'A') && (xz != 'C')) {
			cout << "1110" << "\n";
			return 0;
		}
	}
	if (rz == 'C') {
		if (xz != 'B') {
			cout << "1110" << "\n";
			return 0;
		}
	}
	if (rz == 'D') {
		if (xz != 'F') {
			cout << "1110" << "\n";
			return 0;
		}
	}
	if (rz == 'F') {
		if (xz != 'D') {
			cout << "1110" << "\n";
			return 0;
		}
	}
	cout << "1111" << "\n";
	return 0;
}
