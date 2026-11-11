#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T;
int n,k;
int u[N],v[N];
int fa[N],dis[N];
bool flag[N];
int ans;
vector<int>g[N];
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(flag[i])fa[i]=i;
		else	fa[i]=0;
	}
	for(int i=1;i<n;i++)
		if(flag[u[i]]&&flag[v[i]])
			merge(u[i],v[i]);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(i==find(i))
			cnt++;
	return cnt==2;
}
int cal()
{
	fill(dis+1,dis+n+1,-1);
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(flag[i])
		{
			dis[i]=0;
			q.push(i);
		}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:g[u])
		{
			if(dis[v]!=-1)continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	return *max_element(dis+1,dis+n+1);
}
void dfs(int step,int cnt)
{
	if(cnt==k)
	{
		if(check())ans=min(ans,cal());
		return;
	}
	if(step==n+1)return;
	dfs(step+1,cnt);
	flag[step]=true;
	dfs(step+1,cnt+1);
	flag[step]=false; 
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	ans=INT_MAX;
	if(k==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				flag[i]=flag[j]=true;
				if(check())
					ans=min(ans,cal());
				flag[i]=flag[j]=false;
			}
	}
	else	dfs(1,0);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		solve();
	} 
	return 0;
}
/*
Ô¤¼Æ20 
*/ 
