#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;

struct node {
	int nums[35];
	int flag;
} e[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int l = 30;
		while (l >= 0) {
			if (k >= pow(2, l)) {
				e[i].nums[l] = 1;
				k -= pow(2, l);
			}
			l--;
		}
		e[i].flag = 1;
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (e[j].nums[i] != 0 && e[j].flag) {
				cnt++;
			}
		}
		if (cnt >= m) {
			for (int j = 1; j <= n; j++) {
				if (e[j].nums[i] == 0) {
					e[j].flag = 0;
				}
			}
			ans += pow(2, i);
		}
	}
	cout << ans;
	return 0;
}
