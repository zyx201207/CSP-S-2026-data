#include <bits/stdc++.h>
using namespace std;
#define int long long

bool huiwen(string s) {
	string s1 = s;
	reverse(s1.begin(), s1.end());
	if (s1 == s) {
		return 1;
	} else {
		return 0;
	}
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s2 = "";
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum += a;
		char b;
		cin >> b;
		for (int j = 1; j <= a; j++) {
			s2 = s2 + b;
		}

	}
	if (huiwen(s2) == 1) {
		cout << 0;
	}


	else {
		int ans = 0;
		int sum1 = sum / 2;
		int l = 0, r = sum - 1;
		while (l < r) {
			if (s2[l] != s2[r]) {
				ans++;
			}
			l++;
			r--;
		}
		cout << ans;
	}
	return 0;
}