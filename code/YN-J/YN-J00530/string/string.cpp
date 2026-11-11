#include <bits/stdc++.h>
using namespace std;
#define int long long

struct hws {
	int sl;
	char zm;
} a[200005];
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int maxx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sl >> a[i].zm;
		maxx = max(maxx, a[i].sl);
	}
	if (n == 1) {
		cout << 0;
	} else if (n <= 2000 && maxx <= 50) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i].sl; j++) {
				s = s + a[i].zm;
			}
		}
		int sum = 0;
		int p = s.size() - 1;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] == s[p]) {

			} else {
				sum++;
			}
			p--;
		}
		cout << sum;
	}
	return 0;
}
