#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,int>;
const int M=5e5+10,N=510;
const long long INF=2e18;
int t[M];
long long dis[N];
vector<pii> g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			g[i+m].push_back({v,w});
			g[v].push_back({i+m,w});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m+n;i++) dis[i]=INF;
		dis[x]=0;
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		pq.push({0,x});
		while(!pq.empty())
		{
			auto q=pq.top();
			pq.pop();
			long long d=q.first;
			int u=q.second;
			if(d<dis[u]) continue;
			for(auto nq:g[u])
			{
				int v=nq.first;
				long long w=nq.second;
				long long nd=d+w;
				if(nd<dis[v])
				{
					dis[v]=nd;
					pq.push({nd,v});
				}
			}
		}
		cout<<t[x]*1ll+t[y]*1ll+dis[y]<<endl;
	}
	return 0;
}
