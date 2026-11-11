#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+10,M=510;
int wt[N];
vector<pair<int,int>>to[N];
int gtl[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		while(k--){
			int v,t;
			cin>>v>>t;
			to[m+j].push_back({v,t});
			to[v].push_back({m+j,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)gtl[i][j]=2e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<to[i].size();j++){
			for(int k=j+1;k<to[i].size();k++){
				int u=to[i][j].first-m,v=to[i][k].first-m,w=to[i][j].second+to[i][k].second;
				gtl[u][v]=gtl[v][u]=min(gtl[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gtl[i][j]=min(gtl[i][j],gtl[i][k]+gtl[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<gtl[i][j]<<"\n";
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int mn=2e18;
		for(auto &u:to[x]){
			for(auto &v:to[y]){
				int w=u.second+v.second+gtl[u.first-m][v.first-m];
				mn=min(mn,w);
			}
		}
		cout<<wt[x]+wt[y]+mn<<"\n";
	}
	return 0;
}