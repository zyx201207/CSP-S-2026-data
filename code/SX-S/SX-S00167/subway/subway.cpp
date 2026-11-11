#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const int N=6e5+5;
ll c,n,m,d,q,dis[N],v[N];
vector<pii> vt[N];
ll T,to[N],W[N];
//struct lk{
//	int lst,mn=-1;
//}a[20005][20005];
map<pii,pii> mp;
void Dijkstra(ll s)
{
	for(int i=1;i<=2*m+n;i++) dis[i]=1e18,v[i]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	dis[s]=0;pq.push({0,s});
	while(!pq.empty())
	{
		ll x=pq.top().second;
		pq.pop();
		if(v[x]) continue;
		v[x]=1;
		for(auto in:vt[x])
		{
			ll ed=in.first,vl=in.second;
			if(dis[ed]>=dis[x]+vl)
			{
				dis[ed]=dis[x]+vl;
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
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c>=12&&c<=19)
	{
		for(int i=1;i<=m;i++) cin>>W[i];
		for(int i=1;i<=n;i++)
		{
			ll k;cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>to[j]>>T;
				if(j>1)
				{
					mp[{to[j-1],to[j]}].first=i,mp[{to[j-1],to[j]}].second=1;
					for(int ii=1;ii<=m;ii++)
					{
						ll klst=mp[{ii,to[j-1]}].first,kmn=mp[{ii,to[j-1]}].second;
						if(kmn==0) continue;
						mp[{ii,to[j]}].first=i;
						if(klst==i) mp[{ii,to[j]}].second=kmn;
						else mp[{ii,to[j]}].second=kmn+1;
					}
				}
			}
		}
		while(q--)
		{
			ll l,r;cin>>l>>r;
			ll anmn=mp[{l,r}].second;
			cout<<2*anmn*T+W[l]+W[r]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		ll w;cin>>w;
		vt[i].push_back({i+m,w});
		vt[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
	{
		ll k;cin>>k;
		while(k--)
		{
			ll ed,w;cin>>ed>>w;
			vt[m+ed].push_back({2*m+i,w});
			vt[2*m+i].push_back({m+ed,w});
		}
	}
	while(q--)
	{
		ll l,r;cin>>l>>r;
		Dijkstra(l);
		cout<<dis[r]<<"\n";
	}
	return 0;
}
