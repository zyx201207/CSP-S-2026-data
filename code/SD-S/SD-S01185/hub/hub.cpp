/*
Calm down and trust yourself, control the match in your pace.
*/
#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define I using
#define AK namespace
#define CSPS2026 std
I AK CSPS2026;
const int maxn=1e6+10,maxm=1e3+10,mod=998244353,inf=1e18;
int t,c,n,m,x,y,z,u,v,w,res,rt,answer,arr[maxn],fa[maxn];
bool vis[maxn];
vector<int>e[maxn];
int getfa(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	if(x==y)return;
	fa[getfa(x)]=getfa(y);
	return;
}
void dfs(int u,int fa,int stp)
{
	if(vis[u]==1)
	{
		answer=min(answer,stp);
		return;
	}
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u,stp+1);
	}
	return;
}
void dfs2(int u,int fa,int stp)
{
	if(stp>res)
	{
		res=stp;
		rt=u;
	}
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u,stp+1);
	}
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	FastIO;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c<=3)
		{
			res=(1ll<<n);
			int awa=inf;
			for(int i=1;i<res;i++)
			{
				answer=inf;
				int cnt=0,ans=0,qwq=0;
				for(int j=1;j<=n;j++)vis[j]=0;
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)vis[j+1]=1;
					cnt+=vis[j+1];
					fa[j+1]=j+1;
				}
				if(cnt!=m)continue;				
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)
					{
						int cur=j+1;
						for(auto v:e[cur])if((i>>(v-1))&1)merge(cur,v);
					}
				}
				for(int j=0;j<n;j++)if((i>>j)&1 and getfa(j+1)==j+1)ans++;
				if(ans>2)continue;
				for(int j=1;j<=n;j++)
				{
					answer=inf;
					dfs(j,0,0);
					qwq=max(qwq,answer);
				}
				awa=min(awa,qwq);
			}
			cout<<awa<<"\n";
			//15 pts ok.
		}
		else if(m==1)
		{
			res=0,rt=0;
			dfs2(1,0,0);
			dfs2(rt,0,0);
			cout<<(res>>1)<<"\n";
		}
		else if(m==2)
		{
			res=0,rt=0;
			dfs2(1,0,0);
			dfs2(rt,0,0);
			cout<<(res>>2)<<"\n"; 
		}
		else cout<<"2\n";
	}
	return 0;
}
/*
...
*/

