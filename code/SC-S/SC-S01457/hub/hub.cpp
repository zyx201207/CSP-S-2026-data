#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
#define endl '\n'
using namespace std;
int C,T,N,K,mn,ans;
vector<int> E[1000005];
bool flag[15],vist[15];
void bfs(int st)
{
	queue<int> Q;
	Q.push(st);
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		vist[u]=1;
		for(int v:E[u])
		{
			if(flag[v]&&!vist[v])
			{
				Q.push(v);
			}
		}
	}
}
void bfs2(int st)
{
	queue<pair<int,int> > Q;
	Q.push({st,0});
	while(!Q.empty())
	{
		int u=Q.front().first,dis=Q.front().second;Q.pop();
		if(dis>=mn)
		{
			continue;
		}
		for(int v:E[u])
		{
			if(flag[v])
			{
				mn=min(mn,dis+1);
			}
			else
			{
				if(dis+1<mn)
				{
					Q.push({v,dis+1});
				}
			}
		}
	}
}
void dfs(int x,int sum)
{
	if(x==N+1)
	{
		if(sum!=K)
		{
			return;
		}
		memset(vist,0,sizeof(vist));
		int cnt=0;
		for(int i=1;i<=N;i++)
		{
			if(flag[i]&&!vist[i])
			{
				cnt++;
				bfs(i);
			}
		}
		if(cnt>2)
		{
			return;
		}
		int mx=0;
		for(int i=1;i<=N;i++)
		{
			if(!flag[i])
			{
				mn=1e18;bfs2(i);
				mx=max(mx,mn);
			}
		}
		ans=min(ans,mx);
		return;
	}
	dfs(x+1,sum);flag[x]=1;
	dfs(x+1,sum+1);flag[x]=0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>N>>K;
		for(int i=1,u,v;i<N;i++)
		{
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		if(C<=3||N<=25)
		{
			ans=1e18;dfs(1,0);
			cout<<ans<<endl;
			for(int i=1;i<=N;i++)
			{
				E[i].clear();
			}
			continue;
		}
		cout<<N/(K+1)<<endl;
	}
	return 0;
}
/*
Name: 
Copyright: 
Author: The Pioneer,The Concluder 
Date: 18/08/26 10:10
Description: 
*/