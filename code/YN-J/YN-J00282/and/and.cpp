#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N], ans, an[N][32], y, is[40], sum;
set<int>e[32];
vector<int>g[32];
bool used[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	is[0] = 1;
	for (int i = 1; i <= 30; i++) {
		is[i] = is[i - 1] * 2;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int b = a[i], j = 30;
		while (b != 0) {
			an[i][j] = b % 2;
			j--;
			b /= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 30; j++) {
			if (an[i][j] == 1) {
				e[j].insert(i);
				g[j].push_back(i);
			}
		}
	}
	for (int i = 0; i <= 30; i++) {
		if (e[i].size() >= m) {
			y = i;
			break;
		}
	}
	for (auto v : g[y]) {
		used[v] = 1;
	}
	ans += is[abs(y - 30)];
	for (int i = y + 1; i <= 30; i++) {
		int res = 0;
		for (auto v : e[y]) {
			if (e[i].count(v) == 1 && used[v] == 1) {
				res++;
			}
		}
		if (res >= m) {
			for (auto v : e[y]) {
				if (e[i].count(v) == 0) {
					used[v] = 0;
				}
			}
			ans += is[abs(i - 30)];
		}
	}
	cout << ans;
	return 0;
}
