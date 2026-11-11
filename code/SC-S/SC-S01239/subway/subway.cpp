#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,M=5e2+10,P=N+M,Q=1e3+1;

ll c,n,m,d,q;
ll a[N];
ll tot,dist[P];
vector<pair<ll,ll>> to[P];
ll ans[Q][Q];

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> a[i];
	}
	tot=m;
	ll k,u,t;
	for(int i=1;i<=n;i++)
	{
		tot++;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> u >> t;
			to[u].push_back(make_pair(tot,t));
			to[tot].push_back(make_pair(u,t));
		}
	}
	for(int i=1;i<=m;i++)
	{
		memset(dist,0x3f,sizeof dist);
		dist[i]=0;
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
		q.push(make_pair(dist[i],i));
		while(!q.empty())
		{
			auto p=q.top();
			ll d=p.first,u=p.second;
			q.pop();
			if(dist[u]<d) continue;
			for(auto v:to[u])
			{
				if(dist[v.first]>dist[u]+v.second)
				{
					dist[v.first]=dist[u]+v.second;
					q.push(make_pair(dist[v.first],v.first));
				}
			}
		}
		for(int j=1;j<=m;j++) ans[i][j]=dist[j];
	}
	while(q--)
	{
		ll u,v;
		cin >> u >> v;
		cout << a[u]+a[v]+ans[u][v] << "\n";
	}
	return 0;
}