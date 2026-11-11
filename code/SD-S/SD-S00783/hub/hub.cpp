#include<bits/stdc++.h>
#define inf 1e9
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
int c,t,n,k;
int col[N],dis[N];
int vis[N],dep[N];
vector<int>e[N];
int ans=inf;
void dfs1(int u)
{
	vis[u]=1;
	for(int v:e[u])
	{
	  if(vis[v]||!col[v])  continue;
	  dfs1(v);
	}
}
void dfs2(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int v:e[u])
	{
	  if(v==fa)  continue;
	  dfs2(v,u);
	}
}
void solve()
{
	cin>>n>>k;ans=inf;
	for(int i=1;i<=n-1;i++)
	{
	  int x,y;
	  cin>>x>>y;
	  e[x].push_back(y);
	  e[y].push_back(x); 
	} 
	for(int i=0;i<(1<<n);i++)
	{
	  int cnt=0;
	  for(int j=0;j<n;j++)  col[j+1]=(i>>j)&1;
	  for(int j=1;j<=n;j++)  if(col[j])  cnt++;
	  if(cnt!=k)  continue;cnt=0;
	  for(int j=1;j<=n;j++)
	    if(col[j])
	    {
	      dfs1(j);
	      cnt++;
		}
	  if(cnt>2)  continue;
	  int sum=0;
	  for(int j=1;j<=n;j++)
	  {
	  	int sum2=inf;
		  for(int k=1;k<=n;k++)  dep[k]=0;
	    dfs2(j,0);
//	      for(int k=1;k<=n;k++)  cout<<dep[k]<<" ";cout<<'\n';
	    for(int k=1;k<=n;k++)
	      if(col[k])
	        sum2=min(sum2,dep[k]);
	    sum=max(sum,sum2);
	  }
//	  cout<<i<<" "<<sum<<"\n";
	  ans=min(ans,sum);
	  for(int j=1;j<=n;j++)  vis[j]=col[j]=0;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)  e[i].clear();
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)  solve();
	return 0;
}

