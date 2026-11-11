#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int M=505,N=500005;
int cid,n,m,dmx,q,w[N],d[M][M];
vector<pii>vec[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cid>>n>>m>>dmx>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int cnt;
		cin>>cnt;
		while(cnt--)
		{
			int x,y;
			cin>>x>>y;
			vec[x].pb({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) d[i][j]=1e18;
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int sz=vec[i].size();
		for(int j=0;j<sz;j++)
		{
			for(int k=j+1;k<sz;k++)
			{
				d[vec[i][j].fi][vec[i][k].fi]=min(d[vec[i][j].fi][vec[i][k].fi],vec[i][j].se+vec[i][k].se);
				d[vec[i][k].fi][vec[i][j].fi]=d[vec[i][j].fi][vec[i][k].fi];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,res=1e18;
		cin>>x>>y;
		for(auto i:vec[x])
		{
			for(auto j:vec[y])
			{
				res=min(res,i.se+d[i.fi][j.fi]+j.se);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
