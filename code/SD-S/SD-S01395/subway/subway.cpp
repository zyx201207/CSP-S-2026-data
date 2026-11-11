#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
using ll=long long;
bool ST;
const int N=505,M=5e5+5;
const ll inf=1e18+5;
int ID,n,m,d,q;ll a[M];
struct edge{int to;ll val;}gr[M][21];int sz[M];
ll f[N][N];
bool ED;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr<<(&ED-&ST)/1024.0/1024<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		while(k--){int a;ll t;cin>>a>>t;gr[a][++sz[a]]={i,t};}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=i==j?0:inf;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=sz[i];j++)
			for(int k=j+1;k<=sz[i];k++){
				int u=gr[i][j].to,v=gr[i][k].to;
				f[v][u]=f[u][v]=min(f[u][v],gr[i][j].val+gr[i][k].val);
			}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		ll ans=inf;int u,v;cin>>u>>v;
		for(int j=1;j<=sz[u];j++)
			for(int k=1;k<=sz[v];k++){
				int x=gr[u][j].to,y=gr[v][k].to;
				ans=min(ans,a[u]+a[v]+f[x][y]+gr[u][j].val+gr[v][k].val);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
// last remote
