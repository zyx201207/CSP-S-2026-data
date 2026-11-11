#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int h[500525],ne[1000025],e[1000025],w[1000025],idx;
void add(int x,int y,int z)
{
	ne[++idx]=h[x];
	h[x]=idx;
	e[idx]=y;
	w[idx]=z;
}
int dist[500525];
int dij(int xx,int y)
{
	for(int i=1;i<=m+n;i++) dist[i]=1e18;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > qe;
	
	qe.push({0,xx});
	dist[xx]=0;
	
	while(!qe.empty())
	{
		int di=qe.top().first,x=qe.top().second;
		qe.pop();
		if(dist[x]<di) continue;
		if(x==y) return di;
		
		for(int i=h[x];i;i=ne[i])
		{
			if(dist[e[i]]>di+w[i])
			{
				dist[e[i]]=di+w[i];
				qe.push({dist[e[i]],e[i]});
			}
		}
	}
}
int tt[500025];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		int k,x,y,t1,t2;
		cin>>k;
		if(k==1) continue;
		cin>>x>>t1>>y>>t2;
		add(y,x,t1+t2);
		add(x,y,t1+t2);
	}
	n=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=tt[x]+tt[y];
		ans+=dij(x,y);
		cout<<ans<<'\n';
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tt[i];
	if(c==9||c==10||c==11)
	{
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			int x,y;
			cin>>x>>y;
			continue;
		}
		for(int j=1;j<=k;j++)
		{
			int A,T;
			cin>>A>>T;
			add(i+m,A,T);
			add(A,i+m,T);
		}
	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=tt[x]+tt[y];
		ans+=dij(x,y);
		cout<<ans<<'\n';
	}
	
	return 0;
}