#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
int c,t,n,m,u,v,fa[15];
vector<int>g[15];
bool findfa(int f)
{
	if(f==fa[f])return f;
	return fa[f]=findfa(fa[f]);
}
int check(int mask)
{
	bool b[15];
	int cnt=0,tmp=0,res=0;
	for(int i=1;i<=n;++i)
	{
		b[i]=((mask>>(i-1))&1);
		if(b[i]==1)++cnt;
		fa[i]=i;
	}
	if(cnt!=m)return 0;
	for(int i=1;i<=n;++i)
		if(b[i]==1)
		{
			for(int v:g[i])
			{
				if(b[v]==1&&findfa(v)!=findfa(i))
				{
					fa[findfa(v)]=findfa(i);
				}
			}
		}
	for(int i=1;i<=n;++i)
		if(b[i]&&findfa(i)==i)
		{
			++tmp;
		}
	if(tmp>2||tmp==0)return 0;
	for(int i=1;i<=n;++i)
	{
		if(b[i])continue;
		int vis[15];
		for(int j=1;j<=n;++j)vis[j]=n+1;
		queue<int>q;
		q.push(i);vis[i]=0;
		while(q.size())
		{
			int now=q.front();q.pop();
			for(int v:g[now])
			{
				if(vis[v]!=n+1)continue;
				else
				{
					vis[v]=vis[now]+1;
					q.push(v);
				}
			}
		}
		int x=n+1;
		for(int j=1;j<=n;++j)
			if(b[j])
				x=min(x,vis[j]);
		res=max(x,res);
	}
//	cout<<mask<<":"<<res<<endl;
	return res;
}
void solve()
{
	cin>>n>>m;
	int ans=n+1;
	for(int i=1;i<n;++i)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int mask=1;mask<(1<<n);++mask)
	{
		if(check(mask)!=0)
		{
			ans=min(ans,check(mask));
		}
	}
	if(n==m)ans=0;
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>t;
//	t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
