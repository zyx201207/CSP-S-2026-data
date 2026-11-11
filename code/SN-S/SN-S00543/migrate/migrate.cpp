#include <bits/stdc++.h>
#include <vector>
using namespace std;
int c,t;
int n,d;
int x[5005];
vector<int>G[5005];
int cnt,ans;
void dfs(int now,int y)
{
	if(now == y)
	{
		cnt++;
		return;
	}
	else if(now > y) return;
	int siz = G[now].size();
	for(int i = 0; i < siz; i++)
	{
		dfs(G[now][i],y);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(i != j && x[j] - x[i] <= d)
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				cnt = 0;
				dfs(i,j);
				if(cnt >= 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
