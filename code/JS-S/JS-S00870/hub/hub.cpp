#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=15;
const int INF=200;
int c,t;
int n,k;
vector<int>v[N];
int use[N],vis[N];
int dis[N];
int ans,anst;
//int f[N],g[N],dep[N];

/*int findmid1(int x,int fa,int flag)
{
	dep[x]=dep[fa]+1;
	g[x]=dep[x];
	for(auto y:v[x][flag])
		if(y!=fa)
		{
			findmid(y,fa);
			g[x]=max(g[x],g[y]);
		}
	f[x]=g[x]-dep[x];
}

int findmid1(int x,int fa,int flag)
{
	dep[x]=dep[fa]+1;
	g[x]=dep[x];
	for(auto y:v[x])
		if(y!=fa)
		{
			findmid(y,fa);
			g[x]=max(g[x],g[y]);
		}
	f[x]=g[x]-dep[x];
}*/

void dfs(int x,int flag)
{
	vis[x]=flag;
	for(auto y:v[x])
		if(use[y]==flag&&vis[y]!=flag)dfs(y,flag);
}

void solve(int s,int x,int fa,int step,int flag)
{
	if(use[x]==flag)dis[s]=min(dis[s],step);
	if(use[x]==flag)return;
	for(auto y:v[x])
		if(y!=fa)
			solve(s,y,x,step+1,flag);
}

bool check(int flag)
{
	int cnt=0;
	for(int j=1,k=1;j<=flag;j*=2,k++)
		if(j&flag)
		{
			if(vis[k]!=flag)
			{
				cnt++;
				dfs(k,flag);
			}
		}
	return (cnt<=2);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=INF;
		for(int i=0;i<=(1<<n)-1;i++)
		{
			int cnt=0;
			for(int j=1,k=1;j<=i;j*=2,k++)
				if(i&j)cnt++,use[k]=i;
			//cerr<<"unre"<<endl;
			if(cnt!=k)continue;
			if(!check(i))continue;
			anst=0;
			for(int i=1;i<=n;i++)dis[i]=INF;
			for(int j=1;j<=n;j++)
			{
				solve(j,j,0,0,i);
				anst=max(anst,dis[j]);
			}
			ans=min(ans,anst);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)vis[i]=use[i]=-1;
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
