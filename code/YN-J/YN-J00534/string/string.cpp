//wr 2026.10.31 CSP rp++!
#include <bits/stdc++.h>
using namespace std;
long long n;

struct node {
	long long len;
	char ch;
};
vector<node>s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		char c;
		cin >> a >> c;
		s.push_back({a, c});
	}
	int l = 0, r = s.size() - 1;
	long long ans = 0;
	while (l < r) {
		long long m = min(s[l].len, s[r].len);
		if (s[l].ch != s[r].ch) {
			ans += m;
		}
		s[l].len -= m;
		s[r].len -= m;
		if (s[l].len == 0)
			l++;
		if (s[r].len == 0)
			r--;
	}
	cout << ans;
	return 0;
}