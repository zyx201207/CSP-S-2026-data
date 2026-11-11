#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long t[500025];                         //出站时间 
vector<pair<int,long long> > stn[500025];    //每个站点通的地铁编号和耗费时间 
long long dis[525][525];                     //两条地铁之间耗费的时间 
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=4e18;
		}
	}for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a;
			long long b;
			cin>>a>>b;
			stn[a].push_back({i,b});
		}
	}for(int i=1;i<=m;i++){
		for(auto p1:stn[i]){
			for(auto p2:stn[i]){
				int u=p1.first;
				int v=p2.first;
				dis[u][v]=min(dis[u][v],p1.second+p2.second);
			}
		}
	}floyd();
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		long long ans=4e18;
		for(auto p1:stn[u]){
			for(auto p2:stn[v]){
				ans=min(ans,dis[p1.first][p2.first]+p1.second+p2.second);
			}
		}cout<<ans+t[u]+t[v]<<endl;
	}return 0;
}
