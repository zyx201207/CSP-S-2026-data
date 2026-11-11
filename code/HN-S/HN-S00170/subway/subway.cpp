#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=5e5+5;
const int M=5e2+5;
const ll INF=2e18;
int c,n,m,d,q;
int w[N];
int vis[M];
int dis[M][M];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;
	}
}
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		} 
	}
}
struct Node{int v,w;};
vector<Node> G1[M],G2[N];
void solve(){
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			G1[i].push_back({a,t});
			G2[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=0;j<G1[i].size();j++){
			int x=G1[i][j].v;
			int wx=G1[i][j].w;
			for(int k=0;k<G2[x].size();k++){
				int y=G2[x][k].v;
				int wy=G2[x][k].w;
				if(!vis[y]) vis[y]=wx+wy;
			}
		}
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			dis[i][j]=dis[j][i]=min(dis[i][j],vis[j]);
		}
	}
	Floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(int i=0;i<G2[x].size();i++){
			int u=G2[x][i].v;
			int wu=G2[x][i].w;
			for(int j=0;j<G2[y].size();j++){
				int v=G2[y][j].v;
				int wv=G2[y][j].w;
				ans=min(ans,wu+dis[u][v]+wv);
			}
		}
		cout<<w[x]+ans+w[y]<<"\n";
	}
	return ;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}  
/*
 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
*/
