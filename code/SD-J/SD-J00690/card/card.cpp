#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, MAXM = 3003;

int n, m, nums[MAXN];
int lstap[MAXM], lfir[MAXN];
int ans[MAXM], cnt[MAXM][MAXM], ap[MAXM];
bool vis[MAXM];

int main() { 
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		ap[nums[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		lstap[nums[i]] = i;
	}
	cnt[nums[n]][nums[n]] = 1;
	vis[nums[n]] = 1;
	for (int i = n - 1; i >= 1; i--) {
		int j = lstap[nums[i]] + 1;
		if (!vis[nums[i]]) {
			cnt[nums[i]][nums[i]] = 1;
			for (int k = 1; k <= m; k++) {
				cnt[nums[i]][k] += cnt[nums[j]][k];
			}
			vis[nums[i]] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			ans[j] += ap[i] * cnt[i][j];
//			cout << cnt[i][j] << " ";
		}
//		cout << "\n";
	}
	ans[nums[n]] = n;
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
