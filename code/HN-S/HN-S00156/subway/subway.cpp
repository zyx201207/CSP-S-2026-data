#include<bits/stdc++.h>
using namespace std;
typedef int ll;

struct node
{
	ll u,v;
	bool operator <(const node &tmp)
	const{
		return tmp.v<v;
	}
};

const ll N=3e4;

ll TEST,n,m,d,t;

ll w[N];
vector<node>a[N];
ll dis[550][N];
bool vis[550][N];
priority_queue<node>q;

void dijstra(ll st)
{
//    priority_queue<node>q;
	q.push({st,0});
	dis[st-m][st]=0;
	while(q.size())
	{
		ll x=q.top().u;
		q.pop();
		if(vis[st-m][x])
		{
			continue;
		}
		vis[st-m][x]=true;
		for(auto i:a[x])
		{
			if(dis[st-m][i.u]>dis[st-m][x]+i.v)
			{
				dis[st-m][i.u]=dis[st-m][x]+i.v;
				q.push({i.u,dis[st-m][i.u]});
			}
		}
	}
	return ;
}

int main()
{
	memset(dis,0x3f,sizeof dis);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>TEST>>n>>m>>d>>t;
	scanf("%d%d%d%d%d",&TEST,&n,&m,&d,&t);
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
//	ll cccnt=0;
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll u,v;
//			cin>>u>>v;
			scanf("%d%d",&u,&v);
//			cout<<++cccnt<<"\n";
			a[u].push_back({m+i,v});
			a[m+i].push_back({u,v});
//			cout<<u<<" "<<v<<"\n";
		}
	}
//    cout<<1<<"\n";
	for(ll i=1;i<=n;i++)
	{
		dijstra(m+i);
//		cout<<i<<"\n";
	}
//	cout<<1<<"\n";
	while(t--)
	{
		ll st,en;
		cin>>st>>en;
		ll ans=1e9;
		for(ll i=1;i<=n;i++)
		{
			ans=min(ans,dis[i][st]+dis[i][en]);
		}
//		cout<<ans+w[st]+w[en]<<"\n";
		printf("%d\n",ans+w[st]+w[en]);
	}

	return 0;
}
