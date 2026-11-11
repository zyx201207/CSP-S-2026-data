#include<bits/stdc++.h>
using namespace std;
int c,tt;
int n,d;
int x[20005],vis[20005],ans,t[5005];
vector<int>tr[20005];
int dfs(int x,int y,int cnt,int dis,int ans)
{
	vis[x]=1;
	if(x==y&&dis==ans) return 1;
	for(int i=0;i<tr[x].size();i++)
	{
		if(vis[tr[x][i]]==1) continue;
		cnt=cnt+dfs(tr[x][i],y,cnt,dis+1,ans);
		vis[tr[x][i]]=0;
	}
	return cnt;
}int dfs2(int x,int y,int dis,int dis2)
{
	if(x==y) 
	{
		return dis2;
	}
	for(int i=0;i<tr[x].size();i++)
	{
		dis=min(dis,dfs2(tr[x][i],y,dis,dis2+1));
	}
	return dis;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tt;
	while(tt--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d||j==i+1)
				{
					tr[i].push_back(j);
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int jj=dfs2(i,j,0x3f3f3f3f,0);
				//cout<<jj<<endl;
				if(dfs(i,j,0,0,jj)==2) ans++;
				//cout<<i<<" "<<j<<" "<<dfs(i,j,0,0,jj)<<endl;
			}
		}
		for(int i=1;i<n;i++)
		{
			if(tr[i].size()!=0) tr[i].pop_back();
		}
		cout<<ans<<endl;
	}
	return 0;
}

