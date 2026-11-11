#include<bits/stdc++.h>
using namespace std;
vector<int>ve[5009];
int used[5009];
int n,k,ans=INT_MAX;
queue<int>q;
int check()
{
	int dis[5009],num=0;
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=n;i++)
		if(used[i])
		{
			q.push(i);
			dis[i]=1;
		}
	while(!q.empty())
	{
		int c=q.front();
		q.pop();
		for(int i=0;i<ve[c].size();i++)
			if(!dis[ve[c][i]])
			{
				dis[ve[c][i]]=dis[c]+1;
				q.push(ve[c][i]);
			}
	}
	for(int i=1;i<=n;i++)
		num=max(num,dis[i]-1);
	return num;
}
void dfs(int a)
{
	if(a+2>k)
	{
		ans=min(ans,check());
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i])
			for(int j=0;j<ve[i].size();j++)
				if(!used[ve[i][j]])
				{
					used[ve[i][j]]=1;
					dfs(a+1);
					used[ve[i][j]]=0;
				}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=INT_MAX;
		memset(ve,0,sizeof(ve));
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			ve[v].push_back(u);
			ve[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				memset(used,0,sizeof(used));
				used[i]=1,used[j]=1;
				dfs(1);
			}
		cout<<ans<<endl;
	}
	return 0;
}
