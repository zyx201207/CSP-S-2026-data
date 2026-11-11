#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt = 0;
	cin >> n;
	string s, s1, s2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	int cd = s.size();
	int yb1 = ceil(cd * 1.0 / 2);
	int yb2 = cd / 2;
	s1 = s.substr(0, yb2);
	s2 = s.substr(yb1, yb2);
	for (int i = 0; i < yb2; i++) {
		if (s1[i] != s2[i]) {
			cnt++;
		}
	}
//	cout << s << "\n" << s1 << "\n" << s2 << "\n";
	cout << cnt;
	return 0;
}