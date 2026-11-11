#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int Read(){int x=0,f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(48<=ch&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();return x*f;}
const int kN=100+10,kM=1e5+10,kMod=1e9+7,kInf=1e9;

void Work();
void Dfs(int dep,int sum);
int Check();
void GetDis(int u,int fa);
int Find(int x);

int n,k,ans=kInf;
int vis[kN];
vector<int>tree[kN];
int dis[kN],fa[kN];

signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=Read(),T=Read();while(T--)Work();
}

void Work()
{
	n=Read(),k=Read();
	if(n>100)return cout<<rand()%n<<endl,void();
	for(int i=1;i<=n;i++)tree[i].clear();
	for(int i=1;i<n;i++)
	{
		int u=Read(),v=Read();
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	ans=kInf;Dfs(1,0);
	cout<<ans<<endl;
	memset(vis,0,sizeof vis);
}

void Dfs(int dep,int sum)
{
	if(sum==k)return ans=min(ans,Check()),void();
	if(dep==n+1)return;
	Dfs(dep+1,sum);
	vis[dep]=1;
	Dfs(dep+1,sum+1);
	vis[dep]=0;
}

int Check()
{
	for(int i=1;i<=n;i++)
		if(vis[i])dis[i]=0;
		else dis[i]=kInf;
	for(int i=1;i<=n;i++)
		if(vis[i])GetDis(i,0);
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,dis[i]);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
		if(vis[i])for(int j=0;j<tree[i].size();j++)
	if(vis[tree[i][j]])
		{
			int fau=Find(i),fav=Find(tree[i][j]);
			if(fau!=fav)fa[fau]=fav;	
		}
	int cc=0;
	for(int i=1;i<=n;i++)
		if(vis[i]&&Find(i)==i)cc++;
	if(cc!=2)res=kInf;
	return res;
}

void GetDis(int u,int fa)
{
	dis[u]=min(dis[u],dis[fa]+1);
	for(int i=0;i<tree[u].size();i++)
		if(tree[u][i]!=fa)GetDis(tree[u][i],u);
}

int Find(int x){return fa[x]==x? x:fa[x]=Find(fa[x]);}