#include <bits/stdc++.h>
using namespace std;
int n, m, a[300010], ans[300010];
bool t[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	stack<int> st;
	for (int  i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			if (t[a[j]]) {
				while (st.top() != a[j]) {
					t[st.top()] = 0;
					st.pop();
				}
				st.pop();
			}
			st.push(a[j]);
			t[a[j]] = 1;
		}
		for (int j = 1; j <= m; j ++) {
			ans[j] += t[j];
			t[j] = 0;
		}
		while (st.size()) {
			st.pop();
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
