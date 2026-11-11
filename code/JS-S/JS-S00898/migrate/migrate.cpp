#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
struct node
{
	int v,w;
};
int n,d,a[100005],cnt=0;
vector<node> g[100005];
priority_queue<PII,vector<PII>,greater<PII> > q;
int dis[100005],f[100005];
void dij(int s)
{
	memset(f,0,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	f[s]=1;
	q.push({0,s});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		for(auto v:g[u.second])
		{
			if(f[v.v]) continue;
			if(dis[v.v]>dis[u.second]+v.w)
			{
				dis[v.v]=dis[u.second]+v.w;
				q.push({dis[v.v],v.v});
			}
		}
	}
}
int fl[100005];
void dfs(int l,int x,int t,int k,int now)
{
	if(cnt>2) return ;
	if(now>dis[x]) return ;
	if(x<l) return ;
	if(x>t) return ;
	if(fl[x]) return ;
	if(x==t)
	{
		if(now==k) cnt++;
		return ;
	}
	fl[x]=1;
	for(auto v:g[x])
	{
		dfs(x,v.v,t,k,now+1);
	}
	fl[x]=0;
}
void cclear()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<=300;i++)
	{
		while(g[i].size()) g[i].pop_back();
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,Q;
	cin>>c>>Q;
	while(Q--)
	{
		cclear();
		cin>>n>>d;
		if(n>300)
		{
			for(int i=1;i<n;i++) cin>>a[1];
			cin>>a[2];
			int x=d/(a[2]-a[1]);
			int zero=0;
			if(x>1) cout<<(max(n-x*2+1,zero))<<endl;
			else cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					g[i].push_back({j,1});
					g[j].push_back({i,1});
				}
			}
		}
		int ans=0;
		for(int i=1;i<n-1;i++)
		{
			dij(i);
			for(int j=i+2;j<=n;j++)
			{
				cnt=0;
				dfs(i,i,j,dis[j],0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
