#include <bits/stdc++.h>
using namespace std;
unsigned a[500005], cnt[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool flagA = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1]) flagA = 0;
	}
	if (flagA) {
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= m; j++) {
				cnt[j]++;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			stack <int> st;
			vector <bool> used(m + 1, false);
			for (int j = i; j <= n; j++) {
				if (used[a[j]]) {
					while (st.top() != a[j]) {
						used[st.top()] = 0;
						st.pop();
					}
				} else {
					st.push(a[j]);
					used[a[j]] = 1;
				}
			}
			while (st.size()) {
				cnt[st.top()]++;
				st.pop();
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
