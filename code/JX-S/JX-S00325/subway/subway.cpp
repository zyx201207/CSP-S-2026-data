#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define double long double
#define endl '\n'
#define pb push_back
#define now_time (1e3*clock()/CLOCKS_PER_SEC)
using namespace std;
const int inf=LLONG_MAX>>1;
int c,n,m,cc,T,w[500005],d[505][505];
vector<int> p[500005],e[500005];
unordered_map<int,int> t[505];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>cc>>T;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,y;cin>>k;
		while(k--)cin>>x>>y,p[x].pb(i),e[x].pb(y),t[i][x]=y;
		for(int j=1;j<=n;j++)
			d[i][j]=(i==j?0ll:inf);
	}
	for(int k=1;k<=m;k++)
		for(int i=0;i<p[k].size();i++)
			for(int j=i+1;j<p[k].size();j++)
			{
				int u=p[k][i],v=p[k][j];
				d[u][v]=d[v][u]=min(d[u][v],e[k][i]+e[k][j]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(T--)
	{
		int x,y,ans=inf;cin>>x>>y;
		for(int i=0;i<p[x].size();i++)
			for(int j=0;j<p[y].size();j++)
			{
				int u=p[x][i],v=p[y][j];
				ans=min(ans,d[u][v]+t[u][x]+t[v][y]);
			}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
