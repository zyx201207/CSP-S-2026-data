#include <bits/stdc++.h>
using namespace std;
#define int long long

struct k {
	char a;
	int x;
};
const int N = 1e5 + 10;
k s[N];
int n;
int ans;
string s1;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	cin >> n;
	int fi = 1;
	int n1 = n;
	int man = 0;
	while (n1--) {
		cin >> s[fi].x >> s[fi++].a;
		man += s[fi].x;
	}
	fi = 1;
	for (int i = 1; i <= man; i++) {
		s1 += s[fi++].a;
	}
	string s2 = s1;
	reverse(s1.begin(), s1.end());
	if (s1 == s2) {

		cout << 0;
		return 0;
	}
	if (n % 2 == 0) {
		int m = n;
		for (int i = 1; i <= n / 2; i++) {
			if (s[i].a == s[m].a) {
				if (s[i].x != s[m].x) {
					ans += abs(s[i].x - s[m].x);
					m--;
				}
			} else {
				ans += max(s[i].x, s[m].x);
				m--;
			}
		}
	} else {
		int m = n;
		for (int i = 1; i <= (n - 1) / 2; i++) {
			if (s[i].a == s[m].a) {
				if (s[i].x != s[m].x) {
					ans += abs(s[i].x - s[m].x);
					m--;
				}
			} else {
				ans += max(s[i].x, s[m].x);
				m--;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
