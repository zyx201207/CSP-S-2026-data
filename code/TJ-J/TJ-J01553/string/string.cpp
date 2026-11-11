#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int l;
	cin >> l;
	string s;
	string ans;
	string hbd;
	int sum = 0;
	long long a[l + 5];
	for (int i = 0; i < l; i++) {
		cin >> a[i] >> s[i];
		sum = a[i];
		for (int j = 0; j < sum; j++) {
			ans = s[i];
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (s[i] == s[i + 1]) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}