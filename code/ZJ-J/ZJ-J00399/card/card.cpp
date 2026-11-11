#include <bits/stdc++.h>
using namespace std;
int n, m, a[5005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt[5005] = {0};
	for (int i = 1; i <= n; i++) {
		stack<int>st;
		bool vis[5005] = {0};
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] == 0)vis[a[j]] = 1, st.push(a[j]);
			else while (!st.empty() && st.top() != a[j])vis[st.top()] = 0, st.pop();
	 	}
		while (!st.empty())
			cnt[st.top()]++, st.pop();
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " \n"[i == m];
	return 0;
}
