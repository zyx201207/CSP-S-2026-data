#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N=5e5+10,M=505,INF=1e18+10;
int w[N];
int c,n,m,d,q;
vector<pair<int,int>>a[M];
vector<pair<int,int>>h[N]; 
int k[M];
int ans;
int dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
			h[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int x=a[i][j].x,ww=a[i][j].y;
			for(auto e:h[x]){
				dis[i][e.x]=dis[e.x][i]=min(dis[i][e.x],ww+e.y);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int &p=dis[i][j];
				p=min(p,dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INF;
		for(auto e:h[x]){
			for(auto o:h[y]){
				ans=min(ans,e.y+o.y+dis[e.x][o.x]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
