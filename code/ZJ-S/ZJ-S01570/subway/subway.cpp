#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int w[500010];
int a[510][500010];
ll dis[510][510];
vector<int>e[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	memset(dis,0x3f3f3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			a[i][v]=t;
			e[v].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto j:e[i]){    
			for(auto k:e[i]){
				if(j!=k){
//					cout<<j<<' '<<k<<":"<<i<<"->"<<a[j][i]<<' '<<a[k][i]<<endl;
					dis[j][k]=min(dis[j][k],ll(a[j][i]+a[k][i]));
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<i<<','<<j<<":"<<dis[i][j]<<endl;
//	}cout<<endl;
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(auto i:e[u]){
			for(auto j:e[v]){
//				cout<<i<<' '<<j<<endl;
				ans=min(ans,dis[i][j]+w[u]+w[v]+a[i][u]+a[j][v]);
			}
		}cout<<ans<<'\n';
	}
	return 0;
}