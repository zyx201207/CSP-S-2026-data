#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,dis[505][505],w[500005];
struct s{
	long long sub,cost;
};
vector<s> t[500005];
struct node{
	long long v,w;
};
vector<node> g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			t[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:t[i]){
			for(auto k:t[i]){
				long long x=j.sub,y=k.sub;
				if(x==y) continue;
				dis[x][y]=dis[y][x]=min(dis[x][y],j.cost+k.cost);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==1e18||i==j) continue;
//			g[i].push_back({j,dis[i][j]});
//			g[j].push_back({i,dis[j][i]});
//		}
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long start,end,f=0,ans=1e18;
		cin>>start>>end;
		for(auto j:t[start]){
			for(auto k:t[end]){
				long long x=j.sub,y=k.sub;
				if(x==y){
					f=1;
					ans=j.cost+k.cost+w[start]+w[end];
					break;
				}
				ans=min(ans,dis[x][y]+j.cost+k.cost+w[start]+w[end]);
			}
			if(f) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
