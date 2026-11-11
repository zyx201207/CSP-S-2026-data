#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;

long long a[MAXN], pre[MAXN];

inline
int get_sum(int l, int r) {
	return pre[r] - pre[l] - (l - 1) * (a[r] - a[l]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for (int i = 2;i <= n;i++) {
		int index = 0, every_add = a[i] - a[i - 1];
		pre[i] = pre[i - 1] + (i - 1) * every_add;
		if (pre[i] > m) {
			int l = 1, dx = i - 1;
			while(get_sum(l - 1, i) <= m || get_sum(l, i) > m) {
				if (get_sum(l, i) > m) {
					l += dx;
				}
				else {
					l -= dx;
				}
				dx = max(dx >> 1, 1);
			}
			while(get_sum(l, i) > m) l++;
			while(get_sum(l - 1, i) <= m) l--;
			index = l - 1;
		} 
		ans = max(ans, i - index);
	}
	cout << ans;
	return 0;
}
