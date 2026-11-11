#include<bits/stdc++.h>

using namespace std;
int a[500005];
bool vis[300005];
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	stack<int> q;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]>0)
			{
				while(q.top()!=a[j])
				{
					vis[q.top()]=0;
					q.pop();
				}
			}
			else
			{
				q.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}

