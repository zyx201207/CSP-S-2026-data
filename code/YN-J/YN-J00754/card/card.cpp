#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5, N = 3e5 + 5;
int n, a[maxn], m;
string s = "";
int cnt[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int z = 1; z <= n; z++) {
		for (int i = z; i <= n; i++) {
			char c = a[i] - 1 + '1';
			int pos = -1;
			if (s.size() != 0) {
				for (int j = 0; j <= s.size() - 1; j++) {
					if (s[j] == c) {
						pos = j;
						break;
					}
				}
			}

			if (pos == -1) {
				s += c;
			} else {
				s.erase(pos, s.size() - pos);
				s += c;
			}
		}
		for (int j = 0; j <= s.size() - 1; j++) {
			int u = s[j] - '1' + 1;
			cnt[u]++;
		}
		s = "";
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}