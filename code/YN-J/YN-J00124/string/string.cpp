#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int a;
	char c;
} s[200003];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t, y = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s[i].a;
		cin >> s[i].c;
		y += s[i].a;
		if (s[i - 1].c == s[i].c) {
			t--;
			s[i - 1].a += s[i].a;
			i--;
		}
	}
	int i = 1, j = t, sum1 = 0, sum2 = 0, ans = 0;
	for (int k = 1; k <= y / 2; k++) {
		if (s[i].c != s[j].c)
			ans++;
		if (sum1 + 1 > s[i].a) {
			sum1 = 0;
			i++;
		} else
			sum1++;
		if (sum2 + 1 > s[j].a) {
			sum2 = 0;
			j--;
		} else
			sum2++;
	}
	cout << ans;
	return 0;
}