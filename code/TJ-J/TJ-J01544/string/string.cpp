#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	int k;
	char c;
	for(int i = 1; i <= n; i++) {
		cin >> k >> c;
		for(int j = 1; j <= k; j++) {
			s += c;
		}
	}
	int ans = 0;
	for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		if(s[i] != s[j]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
