#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, a[N];
int res;
bool vis[30];
void dfs (int i , int sum , int cnt) {
	if (sum > m)
		return ;
	if (i == n + 1) {
		if (sum == m) {
			res = max(res , cnt);
		}
		return ;
	}
	vis[i] = true;
	int tmp_cnt;
	if (cnt == -1)
		tmp_cnt = a[i];
	else
		tmp_cnt = cnt & a[i];
	dfs(i + 1 , sum + 1 , tmp_cnt);
	vis[i] = false;
	dfs(i + 1 , sum , cnt);
}

int main () {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20) {
		dfs(1 , 0 , -1);
		cout << res;
	} else if (n <= 2000) {
		if (m == 1) {
			int res = -0x3f3f3f3f;
			for (int i = 1; i <= n; i++)
				res = max(res , a[i]);
			cout << res;
		} else if (m == n) {
			int res = a[1];
			for (int i = 2; i <= n; i++)
				res = res & a[i];
			cout << res;
		} else if (m == 2) {
			int res = -0x3f3f3f3f;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					res = max(res , a[i] & a[j]);
				}
			}
			cout << res;
		}
	} else {
		int res = -0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
			res = max(res , a[i]);
		cout << res;
	}
	return 0;
}
