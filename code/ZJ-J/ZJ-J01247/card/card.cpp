#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;

int n, m, a[N], c[M];

void solve1() {
	vector<int> cnt(m + 1);
	for (int i = 1;i <= n;i++) cnt[a[i]]++;
	for (int i = 1;i <= m;i++) {
		c[i] = cnt[i] + c[i - 1];
	}
	for (int i = 1;i <= m;i++) cout << c[i] << " ";
}

void solve2() {
	int cnt = 0, id;//另一个数的最后位置
	for (int i = n;i >= 1;i--) 
		if (a[i] != a[n]) {
			id = i;
			break;
		}
	vector<int> k;
	for (int i = 1;i <= id;i++) if (a[i] == a[id]) cnt++;
	if (a[n] == 1) cout << n << " " << cnt;
	else cout << cnt << " " << n;
}

void solve3() {
	for (int l = 1;l <= n;l++) {
		stack<int> st;
		vector<int> vis(m + 1, 0);
		for (int i = l;i <= n;i++) {
			if (vis[a[i]]) {
				while (!st.empty()) {
					int t = st.top();
					st.pop();
					vis[t] = 0;
					if (t == a[i]) break;
				}
			}
			st.push(a[i]);
			vis[a[i]] = 1;
		}
		while (!st.empty()) {
			int t = st.top();
			st.pop();
			c[t] ++;
		}
	}
	for (int i = 1;i <= m;i++) cout << c[i] << " ";
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool f = 1;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) f = 0;
	}
	
	if (f) solve1();
	else if (m == 1) cout << n;
	else if (m == 2) solve2();
	else if (n <= 5000) solve3();
	else for (int i = 1;i <= m;i++) cout << n << " ";
}