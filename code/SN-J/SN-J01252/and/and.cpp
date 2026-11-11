#include<bits/stdc++.h>
using namespace std;
int n, m, a[222222], dp[16000][16000];
long long maxn = -1000000000000000000;
void dfs(int x, int cnt, long long sum){
	sum &= a[x];
	cnt++;
	if(cnt == m){
		maxn = max(maxn, sum);
		return;
	}
	if(x == 0){
		return;
	}
	for(int i = x + 1; i <= n; i++){
		dfs(i, cnt, sum);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n - m; i++){
		dfs(i, 0, a[i]);
	}
	cout << maxn;
	return 0;
}
