#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	
	cin >> n;
	
	string s = "";
	int num;
	char c;

	for (int i = 0; i < n; ++i) {
		cin >> num >> c;
		
		while (num--) {
			s += c;
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i < s.length() - i - 1; ++i) {
		ans += !(s[i] == s[s.length() - i - 1]);
	}
	
	cout << ans << endl;
	
	return 0;
}