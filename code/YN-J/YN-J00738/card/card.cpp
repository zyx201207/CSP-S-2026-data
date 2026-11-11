#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2e5 + 5;
int n, m;
stack<int> st;
int mp[M], a[N], ans[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		cout << n;
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= m; i++)
			cout << n << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mp[a[j]] == 1) {
				while (st.top() != a[j] && !st.empty())
					st.pop();
			} else {
				mp[a[j]] = 1;
				st.push(a[j]);
			}
		}
		memset(mp, 0, sizeof mp);
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}