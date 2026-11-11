#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define READ_IN_FILE
#define int long long
using namespace std;
const int N=5e5+10,M=5e2+10,P=998244353,inf=0x3f3f3f3f3f3f3f3f;
int n,m,d,q,dis[M][M],w[N];
vector<pair<int,int> >ns[N];
void solve()
{
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int p,t;cin>>p>>t;
			ns[p].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)ns[i].size();j++)
			for(int k=j+1;k<(int)ns[i].size();k++)
				dis[ns[i][j].first][ns[i][k].first]=
				dis[ns[i][k].first][ns[i][j].first]=
				min(dis[ns[i][j].first][ns[i][k].first],
				ns[i][j].second+ns[i][k].second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int u,v,ans=inf;cin>>u>>v;
		for(auto us:ns[u])
			for(auto vs:ns[v])
				ans=min(ans,dis[us.first][vs.first]+w[u]+w[v]+us.second+vs.second);
		cout<<ans<<'\n';
	}
	return;
}
signed main()
{
	FAST
#ifdef READ_IN_FILE
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	int _T_=1,_C_;
#ifdef MSOD
	cin>>_T_;
#endif
	cin>>_C_;
	while(_T_--)solve();
	return 0;
}

