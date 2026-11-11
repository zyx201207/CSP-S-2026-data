#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int a[500005], b[300005], c[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(b, 0, sizeof(b));
		while (!s.empty()) {
			s.pop();
		}
		for (int j = i; j <= n; j++) {
			b[a[j]]++;
			if (b[a[j]] == 2) {
				while (1) {
					int q = s.top();
					if (q == a[j]) {
						break;
					}
					b[q]--;
					s.pop();
				}
				b[a[j]]--;
			} else {
				s.push(a[j]);
			}
		}
		for (int k = 1; k <= m; k++) {
			if (b[k] != 0) {
				c[k]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}