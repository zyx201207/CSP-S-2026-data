#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+5;
const ll inf=1e18;
int n,m,d,q,w[M];
int tot[M];
pair<int,int> g[M][21];
ll f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			g[x][tot[x]++]={i,t};
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<tot[i];j++){
			int u=g[i][j].first;
			for(int k=0;k<tot[i];k++){
				int v=g[i][k].first;
				f[u][v]=min(f[u][v],(ll)g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(int i=0;i<tot[x];i++){
			int u=g[x][i].first;
			for(auto j=0;j<tot[y];j++){
				int v=g[y][j].first;
				ans=min(ans,f[u][v]+g[x][i].second+g[y][j].second+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
