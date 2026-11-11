#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2000005;
vector<int>edge[N];
LL dis[N];
bool vis[N];
int a[N]={};
map<int,int>mp;
void init(int n)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		mp[i]=0;
	}
}
void dj(int r)
{
	dis[r]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,r});
	while(!q.empty())
	{
		auto e=q.top();
		q.pop();
		int d=e.first,u=e.second;
		if(dis[u]==0x3f3f3f3f)continue;
		for(int v : edge[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
}
void dfs(int u,int step,int n)
{
	//cout<<u<<"   ";
	vis[u]=1;
	if(step==dis[u])
	{
		//cout<<endl<<endl;
		mp[u]++;
	}
	if(u==n+1)return;
	for(int v : edge[u])
	{
		if(!vis[v])
		{
			dfs(v,step+1,n);
		}
	}
	vis[u]=0;
}
LL m,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>t;
	while(t--)
	{
	 	int n,d;
		cin>>n>>d;
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		init(n);	
		for(int i=1;i<=n;i++)if(a[i+1]-a[i]<=d)
		{
			edge[i].push_back(i+1);
			//edge[i+1].push_back(i);
			int j=i+2;
			while(a[j]-a[i]<=d && j<=n)
			{
				edge[i].push_back(j);
				//edge[j].push_back(i);
			//	cout<<i<<' '<<j<<endl;
				j++;
			}
		}
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			init(n);
			dj(i);
		//cout<<dis[n]<<endl;
		//	cout<<1<<endl;
			dfs(i,0,n);
			for(int i=1;i<=n;i++)
			{
				if(mp[i]==2)
				{
					ct++;
				}
				// cout<<dis[i]<<' '<<mp[i]<<endl;
			}
		}
		cout<<ct<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
