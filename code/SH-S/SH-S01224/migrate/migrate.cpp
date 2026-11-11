#include<bits/stdc++.h>
using namespace std;
int ans[305][305],x[305],minn[305];
bool vis[305];
vector<int>g[305];
void dfs(int x,int cnt)
{
	ans[x][cnt]++;
	minn[x]=min(minn[x],cnt);
	for(int y:g[x])
	{
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,cnt+1);
		vis[y]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i = 1;i <= n;i++)
		{
			cin>>x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		int sum=0;
		for(int i = 1;i <= n;i++)
		{
			memset(ans,0,sizeof(ans));
			memset(vis,0,sizeof(vis));
			memset(minn,0x3f,sizeof(minn));
			vis[i]=1;
			dfs(i,0);
			for(int j = 1;j <= n;j++)
			{
				if(ans[j][minn[j]]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
