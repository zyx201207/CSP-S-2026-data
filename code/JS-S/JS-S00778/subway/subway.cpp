#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
const int sk=5e2+10,siz=5e5+10;
vector<pii> v[sk],fk[siz];
priority_queue< pii,vector<pii>,greater<pii> > q;
int dis[sk][sk],e[sk][sk],hyw[siz];
void dijk(int s,int *dis)
{
	for(int i=0;i<sk;i++)dis[i]=1e18;
	dis[s]=0,q.push(mk(0,s));
	while(q.size())
	{
		int hyw=q.top().fi,x=q.top().se;q.pop();
		if(dis[x]!=hyw)continue;
		for(pii tp:v[x])
		{
			int y=tp.fi,z=tp.se;
			if(dis[y]>dis[x]+z)dis[y]=dis[x]+z,q.push(mk(dis[y],y));
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	int _,n,m,d,q;
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>hyw[i];
	for(int i=1,z,x,y;i<=n;i++)
	{
		cin>>z;
		while(z--)cin>>x>>y,fk[x].push_back(mk(i,y));
	}
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++)
		for(pii ox:fk[i])
			for(pii oy:fk[i])if(ox.fi!=oy.fi)e[ox.fi][oy.fi]=e[oy.fi][ox.fi]=min(e[ox.fi][oy.fi],ox.se+oy.se);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(e[i][j]<=2e9)
			v[i].push_back(mk(j,e[i][j]));
	for(int i=1;i<=n;i++)dijk(i,dis[i]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=2e18;
		for(pii ox:fk[x])for(pii oy:fk[y])
			ans=min(ans,dis[ox.fi][oy.fi]+ox.se+oy.se);
		cout<<ans+hyw[x]+hyw[y]<<'\n';
	}
	return 0;
}
//15:02