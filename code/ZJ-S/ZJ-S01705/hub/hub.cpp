#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
vector<int>g[N];
int p[N];
int c,t;
int n,k;
int fa[N];
int ans[N];
/*int a[N];
struct tree{
	int l,r,val;
}tr[N*4];
priority_queue<int>pq;
void build(int node,int l,int r)
{
	tr[node].l=l,tr[node].r=r;
	if(l==r) tr[node]=a[l];
	int mid=l+r>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	//
}
*/
inline int read()
{
	int x=0,y=1;
	char ch;
	ch=getchar();
	if(ch=='-') y=-1;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*y;
}
int dp[505][505];
inline void floyd()
{
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int as[N];
bool check()
{
	map<int,int>mp;
	for(int i=1;i<=k;i++) as[i]=ans[i];
	for(int i=1;i<=k;i++)
	{
		while(as[i]!=fa[as[i]])
		{
			as[i]=fa[as[i]];
		}
		mp[as[i]]++;
	}
	if(mp.size()>2) return 0;
	return 1;
}//right?
int res=LLONG_MAX;
void dfs(int t)
{
	if(t==k+1)
	{
		if(!check()) return ;
		int s=LLONG_MIN;
		for(int i=1;i<=n;i++)
		{
			int d=LLONG_MAX;
			for(int j=1;j<=k;j++) d=min(d,dp[i][ans[j]]);
			s=max(s,d);
		}
		res=min(res,s);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]) continue;
		p[i]=1;
		ans[t]=i;
		dfs(t+1);
		p[i]=0;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		memset(dp,0x3f,sizeof dp);
		n=read(),k=read();
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			dp[u][v]=1;
			fa[v]=u;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		floyd();
		dfs(1);
		cout<<res<<'\n';
	}
	return 0;
}

