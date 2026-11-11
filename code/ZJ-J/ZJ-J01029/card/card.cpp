#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int a[N], b[N], ans[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++) {
		int cnt = 0;
		for(int j = i;j <= n;j ++) {
			int k;
			for(k = 1;k <= cnt;k ++){
				if(b[k] == a[j]) break ;
			}
			b[k] = a[j];
			cnt = k;
		}
		for(int j = 1;j <= cnt;j ++)
			ans[b[j]] ++;
	}
	for(int i = 1;i <= m;i ++) cout << ans[i] << ' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
