#include<bits/stdc++.h>
using namespace std;
void dfs(int x,int fa,int siz)
{
	dp[x][2]=1e18;
	for(int i=0;i<q[x].size();i++)
	{
		int to=q[x][i];
		if(to==fa)
			continue;
		dfs(to,x,siz);
		if(vis[to][0]||cnt[to][0]+1>siz)
		{
			vis[x][0]++;
			if(dp[to][1]<=dp[to][2]||vis[to][2])
				dp[x][2]=dp[to][1],cnt[x][2]=cnt[to][1]+1;
			else
			{
				if(cnt[to][2]+1<=siz)
				{
					dp[x][2]=dp[to][2];
					cnt[x][2]=min(cnt[x][2],cnt[to][2]+1);
				}
				else
				{
					dp[x][2]=dp[to][2]+1;
					cnt[x][2]=siz;
				}
			}
		}
		if(cnt[to][0]+1>siz)
			dp[x][1]+=dp[to][1],dp[x][3]+=dp[to][1],hg=max(hg,dp[to][3]-dp[to][1]);
		if(vis[to][2]==0&&cnt[to][2]+1<=siz)
			hg=max(hg,dp[to][2]-dp[to][1]);
		else if(vis[to][2]==0&&cnt[to][2]+1==siz)
			hg=max(hg,dp[to][2]+1-dp[to][1]);
		if(cnt[x][0]<cnt[to][0]+1)
		{
			sec=cnt[x][0];
			cnt[x][0]=cnt[to][0]+1;
		}
		else if(cnt[to][0]+1>sec)
			sec=cnt[to][0];
	}
	cnt[x][1]=-siz-1;
	cnt[x][3]=-siz-1;
	dp[x][1]++;
	dp[x][3]++;
	if(vis[x][0]>1)
		vis[x][2]=1;
	else if(vis[x][0]==1)
	{
		if(cnt[x][2]<0)
		{
			
		}
	}
	else
		vis[x][2]=0;
	if(cnt[x][0]>siz)
		vis[x][0]=1;
	if(cnt[x][2]<=0)
	{
		if(cnt[x][2])
	}
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
			dp[i][j]=0;
	dfs(1,0,x);
	int res=min(dp[1][1],dp[1][3]);
	if(vis[1][2]==0)
		res=min(res,dp[1][2]);
	if(vis[1][4]==0)
		res=min(res,dp[1][4]);
	if(res<=k)
		return 0;
	return 1;
}
int main()
{
	cin>>test>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			q[x].push_back(y);
			q[y].push_back(x);
		}
		int l=-1,r=n;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(mid))
				l=mid;
			else
				r=mid;
		}
		cout<<r<<"\n";
	}
	return 0;
}
