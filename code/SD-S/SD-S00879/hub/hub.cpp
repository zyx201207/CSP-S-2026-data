#include<bits/stdc++.h>
using namespace std;
const int N=310;
vector<int> G[N];
int n,k;
int dist[N][N];
int ju[N];
int fa[N];
int ans=0;
void init()
{
	for (int i=1;i<=n;i++) fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	fa[fy]=fx;
}
bool check(vector<int> path)
{
	init();
	for (int i=1;i<(int)path.size();i++)
	{
		merge(path[i],path[i-1]);
	}
	int cnt=0;
	for (int i=2;i<=n;i++)
	{
		if (find(i)!=find(i-1))
		{
			cnt++;
		}
	}
	return cnt<=1;
}
void floyd()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) dist[i][j]=(int)1e9;
		dist[i][i]=0;
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void dfs(int idx,int cnt,vector<int> path)
{
	if (idx>n) return;
	if (cnt==k)
	{
		if (check(path))
		{
			floyd();
			for (int i=1;i<=n;i++)
			{
				int idx=lower_bound(path.begin(),path.end(),i)-path.begin();
				if (idx!=-1 && path[idx]==i)
				{
					ju[i]=0;
					continue;
				}
				int minn=1e9;
				for (int j=1;j<=n;j++)
				{
					minn=min(minn,dist[i][j]);
				}
				ju[i]=minn;
			}
			int maxn=0;
			for (int i=1;i<=n;i++)
			{
				maxn=max(maxn,ju[i]);
			}
			ans=min(ans,maxn);
		}
	}
	path.push_back(idx);
	dfs(idx+1,cnt+1,path);
	path.pop_back();
	dfs(idx+1,cnt,path);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> path;
		ans=1e9;
		dfs(1,0,path);
		cout<<ans<<"\n";
	}
}
