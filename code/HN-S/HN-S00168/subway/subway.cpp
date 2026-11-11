//freopen!!!!!
//solve this question at 16:00
/*
now 15:04
观察发现w似乎是滚木
考虑枚举每个地铁站的路线再建边，跑floyd
m*d+n^3+q*d*q
这样瓶颈只有1e8，非常快 
AC subway7.in at 15:58
*/
#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int> 
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=510,M=5e5+510;
int c,n,m,d,q,a[M],dis[N][N];
vector<pi > g[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>a[i];
	int u,v,w,ans;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			g[v].pb({i,w});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].size();j++){
			u=g[i][j].fi;
			for(int l=j+1;l<g[i].size();l++){
				v=g[i][l].fi,w=g[i][j].se+g[i][l].se;
				dis[u][v]=min(dis[u][v],w);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
//		cout<<'\n';
//	} 
	while(q--){
		ans=1e18;
		cin>>u>>v;
		for(int i=0;i<g[u].size();i++){
			for(int j=0;j<g[v].size();j++){
				pi d1=g[u][i],d2=g[v][j];
			//	if(d1.se+d2.se+dis[d1.se][d2.se]==9) cout<<d1.se<<''
				ans=min(ans,d1.se+d2.se+dis[d1.fi][d2.fi]);
			}
		}
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 

fc subway3.ans subway.out
*/
