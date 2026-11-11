#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int ans[N];
vector<int>c;
int a[N];
bool flg[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		c.clear();
		for (int j = 1; j <= n; j++) {
			flg[a[j]] = 0;
		}
		for (int j = i; j <= n; j++) {
			if (flg[a[j]]) {
				int len = c.size();
				int s = c[len - 1];
				while (s != a[j]) {
					c.pop_back();
					len = c.size();
					s = c[len - 1];
				}
			} else {
				flg[a[j]] = 1;
				c.push_back(a[j]);
			}
		}
		for (auto v : c) {
			ans[v]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
