#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,c,d,q,dis[505][505],w[500005];
vector<pair<int,int> > train[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		for(int j=1;j<=num;j++){
			int a,t;
			cin>>a>>t;
			train[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto tr1 : train[i]){
			for(auto tr2 : train[i]){
				if(tr1.first==tr2.first)continue;
				dis[tr1.first][tr2.first]=tr1.second+tr2.second;
				dis[tr2.first][tr1.first]=tr1.second+tr2.second;
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
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	while(q--){
		int u,v,ans=1e18;
		cin>>u>>v;
		for(auto tr1 : train[u]){
			for(auto tr2 : train[v]){
//				cout<<tr1.first<<" "<<tr2.first<<" "<<tr1.second<<" "<<tr2.second<<" "<<dis[tr1.first][tr2.first]+tr1.second+tr2.second<<endl;
				ans=min(ans,dis[tr1.first][tr2.first]+tr1.second+tr2.second);
			}
		}cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}