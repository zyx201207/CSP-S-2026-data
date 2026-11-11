#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500505];
long long dp[500505];
struct node
{
	int x,w;
};
vector<node>v[500505];
void bfs(int x,int y)
{
	for (int i = 1;i <= m + n;i++) dp[i] = 1e18;
	queue<int>q;
	q.push(x);
	dp[x] = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0;i < v[t].size();i++)
		{
			int a = v[t][i].x,b = v[t][i].w;
			if (dp[a] <= dp[t] + b) continue;
			dp[a] = dp[t] + b;
			q.push(a);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int x,y;
			cin >> x >> y;
			v[m + i].push_back({x,y});
			v[x].push_back({m + i,y});
		}
	}
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		bfs(x,y);
		cout << dp[y] + w[x] + w[y] << "\n";
	}
	return 0;
}
