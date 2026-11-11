#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string cr, sr, cx, sx, ss;
	cin >> cr >> sr >> cx >> sx;
	string s_1 = "1", s_0 = "0";
	if (cr == cx) {
		ss += s_1;
	} else {
		ss += s_0;
	}
	if (sr[0] == sx[0] && sr[1] == sx[1]) {
		ss += s_1;
	} else {
		ss += s_0;
	}
	int cj = abs(sr[2] - sx[2]);
	if (sr[2] <= 'C') {
		if (sx[2] <= 'C') {
			ss += s_1;
			if (cj == 1) {
				ss += s_1;
			} else {
				ss += s_0;
			}
		} else {
			ss += s_0;
			ss += s_0;
		}
	} else {
		if (sx[2] <= 'D') {
			ss += s_1;
			ss += s_1;
		} else {
			ss += s_0;
			ss += s_0;
		}
	}
	cout << ss;
	return 0;
}