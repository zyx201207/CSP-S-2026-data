#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, cc;
string s, ss, ans;

string init(string s) {
	if (s[2] == 'A')return "A";
	else if (s[2] == 'B')return "B";
	else if (s[2] == 'C')return "C";
	else if (s[2] == 'D')return "D";
	else if (s[2] == 'F')return "F";
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	if (c == cc) {
		ans += "1";
		if (s[0] == ss[0] && s[1] == ss[1]) ans += "1";
		else ans += "0";

		if (s[0] == ss[0] && s[1] == ss[1]) {
			if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C') {
				if (ss[2] == 'A' || ss[2] == 'B' || ss[2] == 'C')ans += "1";
				else ans += "0";
			} else {
				if (ss[2] == 'D' || ss[2] == 'F')ans += "1";
				else ans += "0";
			}
		} else ans += "0";

		if (s[0] == ss[0] && s[1] == ss[1]) {
			string now = "";
			now += init(s), now += init(ss);
			sort(now.begin(), now.end());
			if (now == "AB" || now == "BC" || now == "DF")ans += "1";
			else ans += "0";
		} else ans += "0";
	} else cout << "0000";
	cout << ans;
	return 0;
}