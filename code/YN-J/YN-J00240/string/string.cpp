#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
	int a;
	char c;
} s[N];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].c;
	}
	long long l = 0, r = n, ans = 0;
	while (l <= r) {
		if (s[l].c != s[r].c) {
			ans += min(s[l].a, s[r].a);
		}
		if (s[l].a > s[r].a) {
			s[l].a -= s[r].a;
			r--;
		} else if (s[l].a == s[r].a) {
			l++;
			r--;
		} else if (s[l].a < s[r].a) {
			s[r].a -= s[l].a;
			l++;
		}
	}
	cout << ans;
	return 0;
}