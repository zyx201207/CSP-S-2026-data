#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500000;
const int INF = 1000000000;
int n, m;
int a[MAXN + 5];
int chu;
int dfs(int pos, int cnt, int res)
{
	if(cnt == m)
		return res;
	if(pos == n && cnt < m)
		return -INF;
	pos++;
	res = max(dfs(pos, cnt + 1, (res & a[pos - 1])), dfs(pos, cnt, res));
	return res;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		chu = max(chu, dfs(i, 1, a[i]));
	cout << chu;
	return 0;
}
