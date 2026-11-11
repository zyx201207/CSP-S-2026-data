#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll,ll>;
ll w[500010],d[500510];
bool vis[500510];
vector <p> a[500510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll n,m,di,c,k,q,x,y;
	cin>>c>>n>>m>>di>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x].push_back({i+m,y});
			a[i+m].push_back({x,y});
		}
	}
	while (q--)
	{
		cin>>x>>y;
		memset(d,0x3f,sizeof d);
		d[x] = 0;
		priority_queue <p,vector<p>,greater<p>> pq;
		memset(vis,0,sizeof vis);
		pq.push({0,x});
		while (! pq.empty())
		{
			ll u = pq.top().second;
			pq.pop();
			if (vis[u]) continue;
			if (u==y) break;
			vis[u] = 1;
			for (p ppp:a[u])
			{
				ll v = ppp.first;
				ll t = ppp.second;
				if (d[v]>d[u]+t)
				{
					d[v] = d[u]+t;
					pq.push({d[v],v});
				}
			}
		}
		cout<<w[x]+w[y]+d[y]<<'\n';
	}
	return 0;
}
