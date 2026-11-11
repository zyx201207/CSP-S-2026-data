#include <bits/stdc++.h>
#define int long long
using namespace std;
//vector <string> s, s1;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, sum = 0, ans = 0;
	string s, s1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		string c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
//			s.push_back(c);
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		s1 += s[i];
//		s1.push_back(s[i]);
	}
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] != s1[i]) {
			sum++;
		}
	}
	ans = sum / 2;
//	cout << "s: " << s << " s1:" << s1 << "\n"; //ต๗สิ
//	cout << "sum: " << sum << " ans:" << ans << "\n"; //ต๗สิ
	cout << ans;
	return 0;
}
//13~16,22~25 WA