#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
string s1, s2, s3, s4;
void solve() {
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3) cout << "0000";
	else {
		cout << "1";
		string t = "", t1 = "";
		t += s2[0] + s2[1];
		t1 += s4[0] + s4[1];
		if (t != t1) cout << "000";
		else {
			cout << "1";
			char t2 = s2[2], t3 = s4[2];
			if (t2 > t3) swap(t2, t3);
			if (!((t2 == 'A' && t3 == 'B') || (t2 == 'A' || t3 == 'C') || (t2 == 'B' || t3 == 'C') || (t2 == 'D' || t3 == 'F'))) cout << "00";
			else {
				cout << "1";
				if (!(abs(t2 - t3) == 1)) cout << "0";
				else cout << "1";
			}
		}
	}
}
signed main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

