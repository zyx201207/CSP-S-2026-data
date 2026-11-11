#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
const ll inf=1e18;
struct edge{
	int v,w;
};
vector<edge>g[M];
int a[M];
ll f[N][N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			g[v].push_back({i,w});
		}
	}memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(edge j:g[i]){
			ll w=j.w;
			for(edge k:g[i]){
				f[j.v][k.v]=min(f[j.v][k.v],w+k.w);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<f[i][j]<<" \n"[j==n];
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(edge i:g[x]){
			ll w=i.w;
			for(edge j:g[y]){
				ans=min(ans,w+j.w+f[i.v][j.v]);
			}
		}ans+=a[x]+a[y];
		cout<<ans<<'\n';
	}
	return 0;
}
