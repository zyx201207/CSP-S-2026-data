#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans[N];
stack<int> st;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		st = stack<int>();
		memset(s, 0, sizeof(s));
		for (int j = i; j <= n; j++) {
			if (s[a[j]]) {
				while (1) {
					int x = st.top();
					st.pop();
					s[x]--;
					if (x == a[j]) {
						break;
					}
				}
			}
			st.push(a[j]);
			s[a[j]] = 1;
		}
		while (!st.empty()) {
			int x = st.top();
			st.pop();
			ans[x]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

