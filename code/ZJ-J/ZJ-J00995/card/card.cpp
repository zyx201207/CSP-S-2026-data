#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], c[M], t[M], ans[M];
int p[N];
stack<int> st;
int main () {

	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) c[j] = 0;
		for (int j = i; j <= n; j++) {
			c[a[j]]++;
			if (c[a[j]] > 1) {
				while (!st.empty ()) {
					int tt = st.top ();
					st.pop ();
					c[tt]--;
					if (tt == a[j]) break;
				}
			}
			st.push(a[j]);
		}
		while (!st.empty ()) {
			int tt = st.top ();
			ans[tt]++;
			st.pop ();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
