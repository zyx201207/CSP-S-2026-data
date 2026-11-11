#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int a[500005], b[500005], c[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(b, 0, sizeof(b));
		while (!st.empty()) {
			st.pop();
		}
		for (int j = i; j <= n; j++) {
			b[a[j]]++;
			if (b[a[i]] == 2) {
				while (1) {
					int q = st.top();
					if (q == a[j])
						break;
					b[q]--;
					st.pop();
				}
				b[a[j]]--;
			} else
				st.push(a[j]);
			for (int k = 1; k <= m; k++) {
				if (b[k] == 1)
					c[k]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}
