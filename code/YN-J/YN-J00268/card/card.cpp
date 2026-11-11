#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int cnt[M];
int a[N];
int ans[M];
stack<int>st;


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			if (cnt[a[i]] != 0) {
				while (st.top() != a[i]) {
					cnt[st.top()]--;
					st.pop();
				}
			} else {
				cnt[a[i]]++;
				st.push(a[i]);
			}
		}
		for (int i = 1; i <= m; i++) {
			if (cnt[i] != 0) {
				ans[i]++;
				cnt[i] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
