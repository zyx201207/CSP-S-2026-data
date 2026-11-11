#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505,M=5e5+10;
int c,n,m,d,q;
int w[M],e[N][N];
vector<pair<int,int>> vis[M];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=1e18;
		}
	}
}
void floyed(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			vis[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)vis[i].size();j++){
			for(int k=j+1;k<(int)vis[i].size();k++){
				int x=vis[i][j].first,y=vis[i][k].first;
				int ww=vis[i][j].second+vis[i][k].second;
				e[x][y]=min(e[x][y],ww),e[y][x]=min(e[y][x],ww);
			}
		}
	}
	floyed();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<(int)vis[x].size();i++){
			for(int j=0;j<(int)vis[y].size();j++){
				int xx=vis[x][i].first,yy=vis[y][j].first;
				int ww=vis[x][i].second+vis[y][j].second;
				ans=min(ans,w[x]+w[y]+e[xx][yy]+ww);
			}
		}
		cout<<ans<<'\n';
	}
			
	return 0;
}
