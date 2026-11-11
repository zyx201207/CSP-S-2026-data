//梁伯温 西安辅轮中学 SN-J00635
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;

int n;
long long a[maxn];
string c, s;

void solve() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		while (a[i]--) {
			s += c[i];
		}
	}
	s = "s" + s;
	long long len = s.size() - 1;
	long long ans = 0;
	for (long long j = 1; j <= len / 2; j++) {
		if (s[j] != s[len + 1 - j]) {
			s[len + 1 - j] = s[j];
			ans++;
		} else {
			continue;
		}
//		cout << "debug:" << j << " " << s << " " << ans << endl;
	}
	cout << ans << endl;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

/*

3
2 a
2 b
1 c

2

2
2 a
3 a

0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

*/
