#include <bits/stdc++.h>
using namespace std;

struct node {
	char a;
	int num;
} s[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].num >> s[i].a;
	}
	int l = 1, r = n;
	unsigned long long ans = 0;
	while (l < r) {
		int minn = min(s[l].num, s[r].num);
		if (s[l].a != s[r].a) {
			ans += minn;
		}
		s[l].num -= minn;
		s[r].num -= minn;
		if (s[l].num == 0)
			l++;
		if (s[r].num == 0)
			r--;
	}
	cout << ans ;
	return 0;
}