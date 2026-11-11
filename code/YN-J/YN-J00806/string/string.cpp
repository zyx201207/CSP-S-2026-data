#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, ans, a;
char c;
string s;

int hws(string s) {
	string s1 = s;
	int ans = 0;
	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {

		if (s[i] != s1[i]) {
			ans++;
		}
	}

	return ans / 2;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;

		for (int j = 1; j <= a; j++) {

			s += c;
		}
	}

	cout << hws(s);
	return 0;
}