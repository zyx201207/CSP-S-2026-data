#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
using namespace std;

const int N=2e6+5,inf=2e18;

int c,T,n,d,ans;
int lg[N],a[N],tp[N],de[N],f[N][25],in[N];
vector<int> g[N];

void clear()
{
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
		in[i]=0;
		tp[i]=0;
		for(int j=0;j<=lg[de[i]];j++)
			f[i][j]=0;
		de[i]=0;
		a[i]=0;
	}
	ans=0;
}

void dfs(int u,int fa)
{
	de[u]=de[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=lg[de[u]];i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<g[u].size();i++)
		dfs(g[u][i],u);
}

int lca(int u,int v)
{
	if(de[u]<de[v])
		swap(u,v);
	for(int i=lg[de[u]];i>=0;i--)
		if(de[f[u][i]]>=de[v])
			u=f[u][i];
	if(u==v)
		return 0;
	for(int i=lg[de[u]];i>=0;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[n]-a[1]<=d)
	{
		cout<<0<<endl;
		return ;
	}
	a[n+1]=inf;
	for(int i=1;i<=n;i++)
	{
		if(a[n]-a[i-1]<=d)
		{
			tp[i]=i;
			continue;
		}
		int t=upper_bound(a+1,a+n+2,a[i]+d)-a-1;
		if(t==i)
		{
			tp[i]=i;
			continue;
		}
		in[t]++;
		g[t].push_back(i);
		tp[i]=tp[t];
	}
	for(int i=n;i>=1;i--)
		if(tp[i]==i)
			dfs(i,0);
	for(int i=1;i<=n-2;i++)
		if(upper_bound(a+1,a+n+2,a[i]+d)-a-1==i+2&&upper_bound(a+1,a+n+2,a[i+1]+d)-a-1>=i+3)
			ans++;
	for(int i=1;i<=n-1;i++)
	{
		if(tp[i]!=tp[i+1])
			continue;
		int x=lca(i,i+1);
		if(i>1&&(upper_bound(a+1,a+n+2,a[i-1]+d)-a-1==i+1)&&x==i+2)
			ans--;
		ans+=de[x]*in[i+1]; 
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=2;i<=2000000;i++)
		lg[i]=lg[i>>1]+1;
	cin>>c>>T;
	while(T--)
	{
		solve();
		clear();
	}
	return 0;
}
