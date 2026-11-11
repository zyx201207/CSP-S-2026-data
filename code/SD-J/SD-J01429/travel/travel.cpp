#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
void Solve() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	
	if (s1 == s3) cout << 1;
	else cout << 0;
	
	if (s1 == s3 && s2[0] == s4[0] && s2[1] == s4[1]) cout << 1;
	else cout << 0;
	
	bool flag = false;
	char a = s2[2], b = s4[2];
	if (s1 == s3 && s2[0] == s4[0] && s2[1] == s4[1]) {
		if (a == 'A' || a == 'B' || a == 'C') {
			if (b == 'D' || b == 'F') {
				cout << 0;
			}
			else {
				cout << 1;
				flag = true;
			}
		}
		else {
			if (b == 'A' || b == 'B' || b == 'C') cout << 0;
			else {
				cout << 1;
				flag = true;
			}
		}
	}
	else cout << 0;
	
	if (flag) {
		int dlt = abs(a - b);
		if (dlt == 1) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	
	cout << endl;
	return;
}
/*====================*/
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	Solve();
	return 0;
}
