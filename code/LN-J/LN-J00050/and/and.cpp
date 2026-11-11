#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d%d", &n, &m);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (m == 1) {
		//printf("1\n");
		printf("%d\n", *max_element(a.begin(), a.end()));
	}
	else if (m == 2) {
		//printf("2\n");
		int ans = -1;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		printf("%d\n", ans);
	}
	else if (m == n) {
		//printf("3\n");
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
		printf("%d\n", ans);
	}
	else {
		//printf("4\n");
		sort(a.begin(), a.end(), greater<int>());
		int ans = a[0];
		for (int i = 1; i < m; i++)
			ans = ans & a[i];
		printf("%d\n", ans);
	}
	return 0;
}