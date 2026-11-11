#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
vector<int> a(N);
int ans = -1;
vector<int> vis(N);
int sum = 0;

void dfs(int x) {
	for (int i = 0; i < n; i++) {
		sum++;
		a[i]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == vis[j]) {
				a[i] = a[i] * 2;
				vis[j] = 0;
				ans = max(ans, a[i]);
				break;
			}
		}
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < vis.size(); i++) {
		vis[i] = 0;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (sum < m)
			dfs(i);
		else
			sum = 0;
		continue;
	}
	cout << ans;
	return 0;
}