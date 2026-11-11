#include <bits/stdc++.h>
using namespace std;
int n, m;
bool b[500001];
vector<int> a, cnt;
stack<int> st;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 1, 0);
	cnt.resize(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (b[a[j]] == false) {
				st.push(j);
				b[a[j]] = true;
			} else {
				while (a[st.top()] != a[j]) {
					b[a[st.top()]] = false;
					st.pop();
				}
			}
		}
		while (!st.empty()) {
			cnt[a[st.top()]]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[m] << ' ';
	}
	return 0;
}