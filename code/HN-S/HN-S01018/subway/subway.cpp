#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int M=5e5+10;
struct Node{
	int v,w;
};
int c,n,m,d,q;
int w[M];
int k[N];
int id;
vector<Node> g[N+M]; 
int dis[N][N];
int u,v;
void solve(){
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			a+=m;
			g[i].push_back({a,b});
			g[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			dis[i][j]=1e18;
		}
	}
	for(int k=m+1;k<=n+m;k++){
		for(int i=0;i<g[k].size();i++){
			for(int j=i+1;j<g[k].size();j++){
				Node a=g[k][i],b=g[k][j];
				dis[a.v][b.v]=min(dis[a.v][b.v],a.w+b.w);
				dis[b.v][a.v]=min(dis[b.v][a.v],a.w+b.w);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int u=1;u<=m;u++){
			for(int v=u+1;v<=m;v++){
				dis[v][u]=dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		if(u==v){
			cout<<"0\n";
			continue;
		}
		u+=m;
		v+=m;
		int ans=1e18;
		for(Node a:g[u]){
			for(Node b:g[v]){
				ans=min(ans,dis[a.v][b.v]+a.w+b.w);
			}
		}
		cout<<ans+w[u-m]+w[v-m]<<"\n";
	}
	return ;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	int oT_To=1;
//	cin>>oT_To;
	while(oT_To--) solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2




*/
