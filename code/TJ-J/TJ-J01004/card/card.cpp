#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, ans[200005], res[200005], a[200005], nxt[200005];
stack<int> st;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (res[a[j]]) {
					while (!st.empty() && st.top() != a[j]) {
						res[st.top()] = 0;
						st.pop();
					}
					st.push(a[j]);
				} else {
					st.push(a[j]);
					res[a[j]] = 1;
				}
			}
			for (int j = 1; j <= m; j++) {
				ans[j] += res[j];
				res[j] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			printf("%d ", ans[i]);
		}
	} else {
		bool ok = true;
		for (int i = 1; i <= n && ok; i++) {
			if (a[i] > a[i + 1])
			ok = false;
		}
		if (ok) {
			for (int i = n; i >= 1; i--) {
				if (ans[a[i]])
					continue;
				else
				ans[a[i]] = i;
			}
			for (int i = 1; i <= m; i++) 
				printf("%d ", ans[i]);
		} else if (m == 2) {
			for (int i = 1; i <= n; i++) {
				if (a[i] != a[n]) {
					ans[1]++;
					ans[2]++;
				} else {
					ans[a[n]]++;
				}
			}
			printf("%d %d", ans[1], ans[2]);
		} else {
			for (int i = n; i >= 1; i--) {
				if (a[i] != a[i + 1])
					nxt[i] = i;
				else
					nxt[i] = nxt[i + 1];
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					j = nxt[j];
					if (res[a[j]]) {
						while (!st.empty() && st.top() != a[j]) {
							res[st.top()] = 0;
							st.pop();
						}
						st.push(a[j]);
					} else {
						st.push(a[j]);
						res[a[j]] = 1;
					}
				}
				for (int j = 1; j <= m; j++) {
					ans[j] += res[j];
					res[j] = 0;
				}
			}
			for (int i = 1; i <= m; i++) {
				printf("%d ", ans[i]);
			}
		}
	} 
    return 0;
}
