#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int a, b;
	string ai, bi;
	
	cin >> a >> ai >> b >> bi;
	
	bool f = true;
	
	if (a == b) {
		cout << 1;
	} else {
		cout << 0;
		f = false;
	}
	
	int al = (ai[0] - '0') * 10 + (ai[1] - '0');
	int bl = (bi[0] - '0') * 10 + (bi[1] - '0');
	
	if (f && al == bl) {
		cout << 1;
	} else {
		cout << 0;
		f = false;
	}
	
	if (f && ((ai[2] < 'D' && bi[2] < 'D') || (ai[2] > 'C' && bi[2] > 'C'))) {
		cout << 1;
	} else {
		cout << 0;
		f = false;
	}
	
	if (f && abs(ai[2] - bi[2]) == 1) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	
	return 0;
}