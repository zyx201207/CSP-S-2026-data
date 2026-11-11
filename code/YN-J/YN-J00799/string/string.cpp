#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;

struct node {
	int len;
	char z;
} s[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].len >> s[i].z;
	}
	int l = 1, r = n, sc = 0;
	while (l < r) {
		int cut = min(s[l].len, s[r].len);
		s[l].len -= cut;
		s[r].len -= cut;
		if (s[l].z != s[r].z)
			sc += cut;
		if (s[l].len == 0)
			l++;
		if (s[r].len == 0)
			r--;
	}
	if (l > r) {
		l--, r++;
		int cut = min(s[l].len, s[r].len);
		s[l].len -= cut;
		s[r].len -= cut;
		if (s[l].z != s[r].z)
			sc += cut;
	}
	cout << sc;
	return 0;
}