#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define int long long
using namespace std;
const int tmax=2e9+5;
struct node{
	int to,w;
};
int c,n,m,d,q,st,nd,w[500005];
vector<node>ve[1510];//500510
vector<node>ve2[1510];
int dis[500005];
bool vis[500005];
int mp[605][605];
//void dij(int s){
//	
//	for(auto 
//}
void solve_1to8(){//m+n<=600
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			mp[i][j]=tmax;
		} 
	}
	for(int ln=1;ln<=n;ln++){//lines
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
//			cin>>a>>t;
			scanf("%lld",&a);
			scanf("%lld",&t);
			ve[m+ln].push_back({a,t});
			ve[a].push_back({m+ln,t});
			mp[m+ln][a]=mp[a][m+ln]=t;
		} 
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		cin>>st>>nd;
		cout<<w[st]+w[nd]+mp[st][nd]<<endl;
	}
}
//void solve_7to11(){
//	for(int i=m+1;i<=m+n;i++){
//		int u=ve[i][0].to,v=ve[i][1].to;
//		int w=ve[i][0].w+ve[i][1].w;
//		ve2[u].push_back({v,w});
//		ve2[v].push_back({u,w});
//	}
//	while(q--){
//		cin>>st>>nd;
////		dij(st);
//		cout<<w[st]+w[nd]+dis[nd];
//	}
//}
//void solve_22to23();
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	if(c<=8){
		solve_1to8();
		return 0;
	}
	
	for(int ln=1;ln<=n;ln++){//lines
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			scanf("%lld",&a);
			scanf("%lld",&t);
//			cin>>a>>t;
			if(k==1)continue;
			ve[m+ln].push_back({a,t});
			ve[a].push_back({m+ln,t});
		} 
	}
	
//	else if(7<=c&&c<=11){
//		solve_7to11();
//	}
//	else if(c==22||c==23){
//		solve_22to23();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

