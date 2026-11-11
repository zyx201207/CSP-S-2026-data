#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,ans[1000010],vis[1000010],flag[1000010],sz[1000010],co=1e18;
vector<ll> g[1000010];
struct node
{
	ll v,w;
	friend bool operator <(node a,node b)
	{
		return a.w>b.w;
	}
};
void dij(ll fi,ll se)
{
	for(int i=0;i<=n;i++)
	{
		ans[i]=1e18;
		vis[i]=0;
	}
//	memset(ans,0x3f3f3f3f,sizeof(ans));
//	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({fi,0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		ll u=now.v,val=now.w;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			ll to=g[u][i];
			if(ans[to]>val+1)
			{
				ans[to]=val+1;
				q.push({to,ans[to]});
			}
		}
	}
}
void dfs(ll pos,ll la,ll tot)
{
	if(pos==k+1)
	{
		ll maxn=0;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				ll t3=1e18;
				for(int j=1;j<=pos;j++)
				{
					dij(i,sz[j]);
					t3=min(t3,ans[sz[j]]);
				}
				maxn=max(maxn,t3);
			}
		}
//		cout<<sz[1]<<" "<<sz[2]<<" "<<sz[3]<<endl;
//		if(maxn==1)
//		{
//			cout<<sz[1]<<" "<<sz[2]<<" "<<sz[3]<<endl;
//		}
		co=min(co,maxn);
		return;
	}
	if(tot>2)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			ll tt=0;
			flag[i]=1;
			sz[pos]=i;
			for(int j=0;j<g[la].size();j++)
			{
				if(g[la][j]==i)
				{
					tt=1;
				}
			}
//			if(i==3&&la==2)
//			{
//				if(la==2)
//				{
//					for(int j=0;j<g[la].size();j++)
//					{
//						cout<<g[la][j]<<" ";
//					}
//					cout<<endl;
//				}
//				cout<<tot<<" "<<tt<<endl;
//			}
//			if(la==3&&i==9)
//			{
//				if(la==2)
//				{
//					for(int j=0;j<g[la].size();j++)
//					{
//						cout<<g[la][j]<<" ";
//					}
//					cout<<endl;
//				}
//				cout<<tot<<" "<<tt<<endl;
//			}
			if(tt)
			{
				dfs(pos+1,i,tot);
			}
			else
			{
				dfs(pos+1,i,tot+1);
			}
			flag[i]=0;
			sz[pos]=0;
		}
	}
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		co=1e18;
		cin>>n>>k;
		for(int j=1;j<=n;j++)
		{
			g[j].clear();
		}
		for(int j=1;j<=n-1;j++)
		{
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0,1); 
		cout<<co<<'\n';
	}
	return 0;
}

