#include <bits/stdc++.h>
using namespace std;
int a[500003];
int ans[300003];
bool fa[300003];
vector<int>s[300003];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	a[n + 1] = 0;

	for (int i = n; i >= 1; i--) {

		if (!fa[a[i]]) {
			s[a[i]] = s[a[i + 1]];
			s[a[i]].push_back(a[i]);
			fa[a[i]] = true;
		}

		for (int j : s[a[i]]) {
			ans[j]++;
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}