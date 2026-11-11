#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int X=5e5+5;
long long c,n,m,d,q,w[X],dis[X],vis[X],p[X],t[X];
vector<pii> vt[X];
void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i=1;i<=m;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<vt[x].size();i++)
		{
			int ed=vt[x][i].first,val=vt[x][i].second;
			if(dis[ed]>dis[x]+val)
			{
				dis[ed]=dis[x]+val;
				pq.push({dis[ed],ed});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(n--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>p[i]>>t[i];
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				vt[p[i]].push_back({p[j],t[i]+t[j]});
				vt[p[j]].push_back({p[i],t[i]+t[j]});
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		dij(l);
		cout<<dis[r]+w[l]+w[r]<<"\n";
	}
	return 0;
}