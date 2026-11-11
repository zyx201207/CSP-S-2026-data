#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int num;
	char fuhao;
};
node a[200010], current[200010];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].fuhao;
	}
	int cnt = 0;
	int now = a[1].num;
	for (int i = 2; i <= n; i++) {
		if (a[i].fuhao == a[i - 1].fuhao) {
			now += a[i].num;
		} else {
			cnt++;
			current[cnt] = {now, a[i - 1].fuhao};
			now = a[i].num;
		}
	}
	cnt++;
	current[cnt] = {now, a[n].fuhao};
	int l = 1, r = cnt;
	int ans = 0;
	while (l < r) {
		if (current[l].fuhao == current[r].fuhao) {
			if (current[l].num > current[r].num) {
				current[l].num -= current[r].num;
				r--;
			} else if (current[l].num == current[r].num) {
				l++, r--;
			} else {
				current[r].num -= current[l].num;
				l++;
			}
		} else {
			if (current[l].num > current[r].num) {
				ans += current[r].num;
				current[l].num -= current[r].num;
				r--;
			} else if (current[l].num == current[r].num) {
				ans += current[l].num;
				l++, r--;
			} else {
				ans += current[l].num;
				current[r].num -= current[l].num;
				l++;
			}
		}

	}
	cout << ans;
	return 0;
}