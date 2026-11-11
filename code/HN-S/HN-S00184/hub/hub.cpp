#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define fi first
#define se second
using namespace std;
const int M=1e6+5,N=(1<<10)+5,inf=1e9;
int n,m,C,ans,sz[M],fa[M],dis[M];
vector<int> vt[M];
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
void uniset(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
		return;
	fa[x]=y;
}
queue<int> q;
void cle()
{
	for(int i=1;i<=n;i++)
		vt[i].clear();
}
void solve()
{
	cin>>n>>m;
	ans=inf;
	for(int i=2,x,y;i<=n;i++)
	{
		cin>>x>>y;
		vt[x].emplace_back(y);
		vt[y].emplace_back(x);
	}
	if(n==m)
	{
		cout<<"0\n";
		cle();
		return;
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)!=m)
			continue;
		for(int j=1;j<=n;j++)
			fa[j]=j;
		for(int j=1;j<=n;j++)
		{
			if(!(i&(1<<j-1)))
				continue;
			for(auto v:vt[j])
				if(i&(1<<v-1))
					uniset(j,v);
		}
		int cnt=0,res=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<j-1))
				cnt+=(j==find(j));
		if(cnt>2)
			continue;
		for(int j=1;j<=n;j++)
		{
			dis[j]=inf;
			if(i&(1<<j-1))
				dis[j]=0,q.push(j);
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			res=max(res,dis[x]);
			for(auto v:vt[x])
			{
				if(dis[v]>=inf)
				{
					dis[v]=dis[x]+1;
					q.push(v);
				}
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	cle();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>C;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
