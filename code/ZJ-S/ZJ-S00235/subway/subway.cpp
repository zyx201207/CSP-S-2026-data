/*
20261031
T	W	D
10	10	10
	4	4
W	15:28
D	15:32
F	15:36
*/
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int N=5e5+5,M=505;
const ll INF=1e18;
vector<pii>vec[N];
int a[N];
ll d[M][M];
void ATRI()
{
	int n,m,D,q;cin>>n>>m>>D>>q;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		int l;cin>>l;
		for(int j=1,x,y;j<=l;++j)cin>>x>>y,vec[x].push_back({i,y});
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=i==j?0:INF;
	for(int i=1;i<=m;++i)for(int j=0;j<vec[i].size();++j)for(int k=0;k<j;++k)
		d[vec[i][j].first][vec[i][k].first]=min(d[vec[i][j].first][vec[i][k].first],1ll*vec[i][j].second+vec[i][k].second);
	for(int i=1;i<=n;++i)for(int j=1;j<i;++j)d[i][j]=d[j][i]=min(d[i][j],d[j][i]);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--)
	{
		int u,v;cin>>u>>v;ll ans=INF;
		for(auto [u1,d1]:vec[u])for(auto [u2,d2]:vec[v])ans=min(ans,d[u1][u2]+d1+d2);
		cout<<ans+a[u]+a[v]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;cin>>c;ATRI();
	return 0;
}