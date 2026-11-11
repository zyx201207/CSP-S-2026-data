#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s = "";
ll cnt;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; cin >> T;
	for (int j = 1; j <= T; j++) {
		ll x; char y; cin >> x >> y;
		int i = 1;
		for (; i <= x - 10; i += 10) {
			s = s + y + y + y + y + y + y + y + y + y + y;
		}
		for (; i <= x; i++) {
			s = s + y;
		}
	}
	ll l = s.size();
	string t = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != t[i]) cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
