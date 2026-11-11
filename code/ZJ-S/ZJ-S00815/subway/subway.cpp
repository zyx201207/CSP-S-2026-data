#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10,M=5e2+10;
const int INF=1e18;
int c,n,m,d,q,t[N],res=INF;
vector<pair<int,int> > g[N];
int dis[M][M];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size()-1;j++){
			for(int k=j+1;k<g[i].size();k++){
				int x=g[i][j].first,y=g[i][k].first;
				int num=g[i][j].second+g[i][k].second;
				dis[x][y]=min(dis[x][y],num);
				dis[y][x]=min(dis[y][x],num);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;res=INF;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int num=t[x]+t[y]+dis[g[x][i].first][g[y][j].first]+g[x][i].second+g[y][j].second;
				res=min(res,num);
			}
		}
		cout<<res<<"\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}