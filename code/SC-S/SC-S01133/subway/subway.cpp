#include<bits/stdc++.h>

#define ll long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 510,M = 5e5 + 10;
int c,n,m,d,q,w[M];ll f[N][N];
vector<pair<int,int>> in[M];
void upd(ll &x,ll y){x = (x>y?y:x);}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int kl;cin>>kl;
		for(int j=1;j<=kl;++j)
		{
			int ta,tb;cin>>ta>>tb;
			in[ta].push_back(make_pair(i,tb));
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j] = (i!=j) * INF;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<(int)in[i].size();++j)
			for(int k=j+1;k<(int)in[i].size();++k) 
			{
				ll www = in[i][j].second+in[i][k].second;
				upd(f[in[i][j].first][in[i][k].first],www),upd(f[in[i][k].first][in[i][j].first],www);
			}
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) upd(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;++i)
	{
		int x,y;cin>>x>>y;
		ll ans = INF;
		for(int j=0;j<(int)in[x].size();++j)
			for(int k=0;k<(int)in[y].size();++k)
				upd(ans,f[in[x][j].first][in[y][k].first]+in[x][j].second+in[y][k].second);
		cout<<ans + w[x] + w[y]<<"\n";
	}
	return 0;
}