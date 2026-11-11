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
int c,d,t,n,m,x,y,z,u,v,w,ans,arr[maxn],cnt[maxn],dis[maxn];
vector<pair<int,int> >e[maxn];
struct node
{
	int id,dis;
	bool operator<(const node &x)const
	{
		return dis>x.dis;
	}
};
priority_queue<node>q;
void dijkstra(int u)
{
	for(int i=1;i<=n;i++)dis[i]=inf,cnt[i]=0;
	while(!q.empty())q.pop();
	dis[u]=0;
	cnt[u]=1;
	q.push({u,0});
	while(!q.empty())
	{
		auto cur=q.top();
		q.pop();
		int x=cur.id;
		if(cur.dis>dis[x])continue;
		for(auto v:e[x])
		{
			if(dis[x]+v.second==dis[v.first])cnt[v.first]+=cnt[x];
			if(dis[x]+v.second<dis[v.first])
			{
				dis[v.first]=dis[x]+v.second;
				cnt[v.first]=cnt[x];
				q.push({v.first,dis[v.first]});
			}
		}
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	FastIO;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>arr[i],e[i].clear();
		arr[n+1]=inf; 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n+1;j++)
			{
				if(arr[j]-arr[i]>d)break;
				e[i].push_back({j,1});
			}
		}
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=i+1;j<=n;j++)ans+=(cnt[j]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
...
*/

