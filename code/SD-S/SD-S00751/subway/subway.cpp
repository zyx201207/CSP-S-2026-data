#include<bits/stdc++.h>
using ll=long long;
using namespace std;
using pii=pair<int,ll>;
const int N=5e5+5,M=505;

int cid,n,m,d,q;
int w[N];
vector<pii> g1[M],g2[N];
ll f[M][M];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,c;cin>>u>>c;
			g1[i].push_back({u,c});
			g2[u].push_back({i,c});
		}
	}
	memset(f,0x3f3f,sizeof f);
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		for(auto tmp1:g1[i]) for(auto tmp2:g2[tmp1.first])
			f[i][tmp2.first]=min(f[i][tmp2.first],tmp1.second+tmp2.second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=i;j<=n;j++)
//			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
	while(q--)
	{
		int u,v;cin>>u>>v;
		ll ans=1e18;
		for(auto tmp1:g2[u])
			for(auto tmp2:g2[v])
				ans=min(ans,tmp1.second+tmp2.second+f[tmp1.first][tmp2.first]);
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}
