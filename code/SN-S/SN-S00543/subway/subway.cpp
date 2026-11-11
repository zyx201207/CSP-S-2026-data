#include <bits/stdc++.h>
#include <vector>
using namespace std;
int c,n,m,d,q;
int w[100005];
int k[505];
int a[505][500005],t[505][500005];
vector<int>G[500005];
int ans;
void dfs(int now, int y, int sum)
{
	if(now == y)
	{
		ans = max(ans,sum);
		return;
	}
	int siz = G[now].size();
	for(int i = 0; i < siz; i++)
	{
		dfs(G[now][i],y,sum);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		G[i].push_back(x);
		for(int j = 1; j <= x; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		dfs(x, y, w[x] + w[y]);
	}
	return 0;
}
