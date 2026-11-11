#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int M = 5e5 + 10,N = 5e2 + 10;
int c;
int n,m,k;
int d,q;
int w[M];
int dis[N][N];
struct node{
	int u,t;
};
vector<node> e[M];
 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		cin>>k;
		for(int j = 1;j <= n;j++) dis[i][j] = 200000000000000000;
		dis[i][i] = 0;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	for(int i = 1;i <= m;i++){
		for(auto x : e[i]){
			for(auto y : e[i]){
				dis[x.u][y.u] = min(dis[x.u][y.u],x.t + y.t);
				dis[y.u][x.u] = dis[x.u][y.u];
			}
		}
	}	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans = LONG_LONG_MAX;
		for(auto i : e[x]){
			for(auto j : e[y]){
				ans = min(ans,dis[i.u][j.u] + i.t + j.t);
			}
		}
		cout<<ans + w[x] + w[y]<<endl;
	}
	return 0;
}
