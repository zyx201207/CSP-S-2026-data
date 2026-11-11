#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,t,n,k,Minn=1e9,a[N],dis[N][N];
bool vis[N],vis1[N];
struct node
{
	int x,ans;
};
vector<int>v[N];
void bfs(int st)
{
	memset(vis,0,sizeof(vis));
	queue<node>q;
	vis[st]=1;
	dis[st][st]=0;
	q.push({st,0});
	while(!q.empty())
	{
		node x=q.front();
		q.pop();
		for(auto i:v[x.x])
		{
			if(vis[i]) continue;
			vis[i]=1;
			dis[st][i]=x.ans+1;
			q.push({i,x.ans+1});
		}
	}
}
void bfs1(int st)
{
	memset(vis1,0,sizeof(vis1));
	queue<int>q;
	vis1[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto i:v[x])
		{
			if(!vis[i]||vis1[i]) continue;
			vis1[i]=1;
			q.push(i);
		}
	}
}
void dfs(int x,int id)
{
	if(x==k+1)
	{
		if(x!=3)
		{
			for(int i=1;i<=n;++i) vis1[i]=0;
			int cnt=0;
			for(int i=1;i<=n;++i)
			if(vis[i]&&!vis1[i]) bfs1(i),cnt++;
			if(cnt>2) return;
		}
		int Max=0;
		for(int i=1;i<=n;++i)
		{
			int Min=1e9;
			for(int j=1;j<x;++j) Min=min(Min,dis[i][a[j]]);
			Max=max(Max,Min);
		}
		Minn=min(Minn,Max);
		return;
	}
	for(int i=id;i<=n;++i)
	{
		a[x]=i;
		vis[i]=1;
		dfs(x+1,i+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		Minn=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;++i) v[i].clear();
		for(int i=1;i<n;++i)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;++i) bfs(i);
		memset(vis,0,sizeof(vis));
		dfs(1,1);
		cout<<Minn<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
