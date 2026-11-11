#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5e5 + 10;
int ans[N], a[N];
stack<int>s;
bool vis[N];
bool flg;
int kind[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1])
			flg = 1;
	}
	for (int i = 1; i <= n; i++) {
		kind[a[i]] = i;
	}
	if (!flg) {
		for (int i = 1; i <= m; i++) {
			cout << kind[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= m; i++)
			vis[i] = 0;
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (s.size()) {
					if (s.top() == a[j]) {
						s.pop();
						break;
					}
					vis[s.top()] = 0;
					s.pop();
				}
			}
			vis[a[j]] = 1;
			s.push(a[j]);
		}
		while (s.size()) {
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
