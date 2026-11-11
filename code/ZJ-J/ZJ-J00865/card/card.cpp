#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], lst[M], ans[M], b[N], n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		b[j]++;
		while (j <= n) {
			if (lst[a[j]] > j) {
				b[j]--;
				j = lst[a[j]];
				b[j]++;
			}
			j++;
		}
	}
	int add = 0;
	for (int i = 1; i <= n; i++) {
		add += b[i];
		ans[a[i]] += add;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << (i == m ? "\n" : " ");
	}
	return 0;
}
