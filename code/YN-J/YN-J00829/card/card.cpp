#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> ans(m + 1, 0);
	for (int k = 1; k <= n; k++) {
		stack<int> st;
		vector<bool> flag(m + 1, false);
		for (int i = k; i <= n; i++) {
			if (flag[a[i]] == true) {
				while (st.top() != a[i]) {
					flag[st.top()] = false;
					st.pop();
				}
				st.pop();
			}
			flag[a[i]] = true;
			st.push(a[i]);
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}