#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NA=505;
const int MA=5e5+5; 
int c,n,m,d,q;
int dis[NA][NA];
int w[MA];
struct node{
	int a,t;
};
vector<node> g[MA];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto x:g[i]){
			for(auto y:g[i]){
				dis[x.a][y.a]=dis[y.a][x.a]=min(x.t+y.t,dis[x.a][y.a]);
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
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto s:g[x]){
			for(auto e:g[y]){
				ans=min(ans,s.t+e.t+dis[s.a][e.a]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
开考 55 分钟完成。 

齐芒保佑我复杂度正确！ 
*/
