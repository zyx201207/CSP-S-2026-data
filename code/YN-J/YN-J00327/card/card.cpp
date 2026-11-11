#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int s[300005];
deque<int> q;
bool f[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof f);
		for (int j = i; j <= n; j++) {
			if (f[a[j]] == 0) {
				f[a[j]] = 1;
			} else {
				while (q.back() != a[j]) {
					f[q.back()] = 0;
					q.pop_back();
				}
				f[q.back()] = 0;
				q.pop_back();
			}
			q.push_back(a[j]);
			f[a[j]] = 1;
		}
		while (q.size()) {
			s[q.back()]++;
			q.pop_back();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << s[i] << " ";
	}
	return 0;
}