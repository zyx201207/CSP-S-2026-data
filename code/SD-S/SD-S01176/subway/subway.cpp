#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define buil(x) __builtin_popcount(x);
#define PII pair<long long,long long>

#define se second
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
using namespace std;
const int M=2e4+5;
const int N=505;
int c,n,m,d,q;
int w[N],a[N][M],t[N][M],k[N];
vector<PII>nea[N];
int x,y;
int vis[M];
void dfs(int u,int lin,int p)//lin线的第p个站点，当前时间 
{
	vis[a[lin][p]]=min(vis[a[lin][p]],u);
	if(a[lin][p]==y) return ;
//	for(int i=p;i<=k[lin];i++)
//	{
//		if(vis[a[lin][i]]>u+t[lin][i]+t[lin][p])
//		{
//			dfs(u+t[lin][i]+t[lin][p],lin,i);
//		}
//	}
	for(auto i:nea[a[lin][p]])
	{
		int nlin=i.first,np=i.second;
		for(int j=1;j<=k[nlin];j++)
		{
			if(vis[a[nlin][j]]>u+t[nlin][np]+t[nlin][j])
			{
				dfs(u+t[nlin][np]+t[nlin][j],nlin,j);
			}
		}
	}
 } 
int query(int x,int y)
{
	for(int i=1;i<=m;i++) vis[i]=1e18;
	for(auto i:nea[x])
	{
		auto lin=i.first;
		auto p=i.second;
		dfs(0,lin,p);
//		cout<<lin<<" "<<p<<" "<<a[lin][p]<<"\n";
	}
	return vis[y];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++)
    	{
    		cin>>a[i][j]>>t[i][j];
    		nea[a[i][j]].push_back({i,j});
		}
	}
	int ans;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=0;
		ans+=w[x]+w[y];
		ans+=query(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}

