#include<bits/stdc++.h>
using ll=int;
using namespace std;
ll c,t;
ll n,k;
vector<ll>g[1100];
ll as[1100];
ll fa[1101];
bool vs[1101];
ll dist[20][20];
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool ch()
{
	ll aa=0,bb=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		for(auto v:g[as[i]])
		{
			if(vs[v])fa[find(v)]=find(as[i]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(vs[as[i]])
		{
			ll x=find(as[i]);
			if(!aa)
			{
				aa=x;
			}
			else if(aa!=x)
			{
				if(!bb)bb=x;
				else if(bb!=x)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
ll res=1e18;
void dfs(ll x,ll p)
{
	if(x==n+1)
	{
		if(p)return ;
		if(!ch())return ;
		ll op=0;
		for(int i=1;i<=n;i++)
		{
			if(!vs[i])
			{
				ll kl=1e18;
				for(int j=1;j<=n;j++)
				{
					if(vs[j])
					{
						kl=min(kl,dist[i][j]);
					}
				}
				op=max(op,kl);
			}
		}
		res=min(res,op);
		return ;
	}
	if(n-x+1==p)
	{
		for(int i=x;i<=n;i++)
		{
			as[k-p+i-x+1]=i;
			vs[i]=1;
		}
		dfs(n+1,0);
		for(int i=x;i<=n;i++)
		{
			vs[i]=0;
		}
		return ;
	}
	if(p)
	{
		as[k-p+1]=x;
		vs[x]=1;
		dfs(x+1,p-1);
		vs[x]=0;
		as[k-p+1]=0;
	}
	dfs(x+1,p);
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			if(c<=3)dist[x][y]=dist[y][x]=1;
		}
		if(c<=3)
		{
			res=1e18;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					if(i==k)continue;
					for(int j=1;j<=n;j++)
					{
						if(j==k||j==i)continue;
						dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
					}
				}
			}
			dfs(1,k);
			cout<<res<<"\n";
		}
	}
	return 0;
}
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/