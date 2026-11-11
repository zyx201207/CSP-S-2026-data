#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=510,maxm=5e5+10;
int c,n,m,d,q,wei[maxm],top[maxm],sta[maxm][25];
ll dis[maxm][25],f[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wei[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=(i==j?0:inf);
		}
		int num;cin>>num;
		while(num--){
			int u,w;cin>>u>>w;
			++top[u],sta[u][top[u]]=i,dis[u][top[u]]=w;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=top[i];j++){
			for(int k=1;k<=top[i];k++){
				int u=sta[i][j],v=sta[i][k];
				f[u][v]=min(f[u][v],dis[i][j]+dis[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int C=1;C<=q;C++){
		int u,v;cin>>u>>v;
		ll ans=inf;
		for(int i=1;i<=top[u];i++){
			for(int j=1;j<=top[v];j++){
				ans=min(ans,dis[u][i]+dis[v][j]+f[sta[u][i]][sta[v][j]]);
			}
		}
		cout<<(ans+wei[u]+wei[v])<<"\n";
	}
	return 0;
}