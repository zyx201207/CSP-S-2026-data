#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50, M = 1e5 + 50;

stack<int> st;

int a[N], m, n, cnt[M], ans[M], vis[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		while (!st.empty()) {
			st.pop();
		}

		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(vis));

		for (int j = i; j <= n; j++) {

			if (cnt[a[j]] == 0) {
				cnt[a[j]] = j;
				st.push(a[j]);
			} else {
				int t = j - cnt[a[j]];

				for (int k = 1; k <= t; k++) {

					st.pop();
				}

				st.push(a[j]);
				cnt[a[j]] = j;
			}
		}

//		cout << i << ":";

		while (!st.empty()) {
			int t = st.top();
//			cout << t << " ";

			if (vis[t] == 0) {
				ans[t]++;
				vis[t] = 1;
			}

			st.pop();
		}

//		cout << "\n";
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	cout << "\n";
	return 0;
}