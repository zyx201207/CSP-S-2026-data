#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int M=5e5+10,N=550;
namespace STD{
	int c,n,m,d,q;
	ll fw[M];
	ll dist[N][N];//集合距离 
	struct node{
		int v;
		ll w;
	};
	vector <node> G[M];//对每个地铁站计集合 
	void work(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>fw[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=(ll)2e18;
			}
		}
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,a,t;j<=k;j++){
				cin>>a>>t;
				G[a].push_back({i,t});
			}
			dist[i][i]=0;
		}
		for(int k=1;k<=m;k++){
			for(auto ni:G[k]){
				for(auto nj:G[k]){
					if(ni.v==nj.v) continue;
					int u=ni.v,v=nj.v;
					dist[u][v]=min(dist[u][v],ni.w+nj.w);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dist[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){

				if(i==k) continue;
				for(int j=i+1;j<=n;j++){
					if(j==k) continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
					dist[j][i]=dist[i][j];
				}
			}
		}
		
		for(int i=1,x,y;i<=q;i++){
			cin>>x>>y;//x->v
			ll ans=LLONG_MAX;
			for(auto ni:G[x]){
				for(auto nj:G[y]){
					ans=min(ans,dist[ni.v][nj.v]+ni.w+nj.w);
				}
			}
			cout<<ans+fw[x]+fw[y]<<"\n";	
		}
		
	}
}
void rw(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rw();
	int T=1;//cin>>T;
	while(T--) STD::work();

	return 0;
}


