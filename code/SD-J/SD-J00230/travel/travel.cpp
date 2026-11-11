#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
string rbx, xbx, r, x;
int rb, xb, rn, xn, rs, xs;

void so() {
	cin >> rbx >> r >> xbx >> x;
	rb = rbx[0] * 10 + rbx[1];
	xb = xbx[0] * 10 + xbx[1];
	if (rb == xb) cout << "1";
	else {
		cout << "0000\n";
		return ;
	}
	rn = r[0] * 10 + r[1];
	xn = x[0] * 10 + x[1];
	if (rn == xn) cout << "1";
	else {
		cout << "000\n";
		return ;
	}
	if ((r[2] == 'D' || r[2] == 'F') && (x[2] != 'D' && x[2] != 'F')) {
		cout << "00\n";
		return ;
	}
	else if ((x[2] == 'D' || x[2] == 'F') && (r[2] != 'D' && r[2] != 'F')) {
		cout << "00\n";
		return ;
	}
	else {
		cout << "1";
		if ((r[2] == 'F' && x[2] == 'D') || (x[2] == 'F' && r[2] == 'D') || (r[2] == 'A' && x[2] == 'B') || (x[2] == 'A' && r[2] == 'B') || (r[2] == 'B' && x[2] == 'C') || (x[2] == 'B' && r[2] == 'C')) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) so();
	return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
!@#$%^&*()_+[]{}~`¡¤
1234567890
02 01D 02 01A

*/



