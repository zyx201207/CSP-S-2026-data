#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=505;
const int inf=1000'000'000'000'000'000ll;
int c,n,m,d,q,dis[M][M],w[N];
struct node{int v,w;};
vector<node>g[N];
vector<node>k[M];
void floyd()
{
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int len,a,t;
		cin>>len;
		while(len--)
		{
			cin>>a>>t;
			k[i].push_back({a,t});
			g[a].push_back({i,t});
		} 
	}
	for(int i=1;i<=n;i++){
		for(auto x:k[i]){
			for(auto y:g[x.v]){
				dis[i][y.v]=min(dis[i][y.v],x.w+y.w);
			}
		}
	}
	floyd();
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(auto x:g[u]){
			for(auto y:g[v]){
				ans=min(ans,w[u]+w[v]+dis[x.v][y.v]+x.w+y.w);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
