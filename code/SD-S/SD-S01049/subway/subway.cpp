#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500100],dis[510][510];
struct node{
	int a,t;
};
vector<node>vec[500100]; 
void spfa(){
	for(int mi=1;mi<=n;mi++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][mi]+dis[mi][j]<dis[i][j]){
					dis[i][j]=dis[i][mi]+dis[mi][j];
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int lp=0;lp<vec[i].size();lp++){
			for(int rp=lp+1;rp<vec[i].size();rp++){
				dis[vec[i][lp].a][vec[i][rp].a]=min(dis[vec[i][lp].a][vec[i][rp].a],vec[i][lp].t+vec[i][rp].t);
				dis[vec[i][rp].a][vec[i][lp].a]=dis[vec[i][lp].a][vec[i][rp].a];
			}
		}
	}
	spfa();
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=w[u]+w[v];
		int sum=2e18;
		for(auto fi:vec[u]){
			for(auto se:vec[v]){
				sum=min(sum,fi.t+se.t+dis[fi.a][se.a]);
			}
		}
		cout<<sum+ans<<"\n"; 
	}
	return 0;
}


