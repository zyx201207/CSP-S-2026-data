#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=505,maxm=500005;
int n,m,c,d,q,k;
ll dis[maxn][maxn];
vector<pair<int,ll> >vec[maxm];
int a;
ll t;
int w[maxm];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		//赌一把 复杂度超不了
		int tot=vec[i].size();
		for(int j=0;j<tot;j++){
			for(int k=j+1;k<tot;k++){
				int x=vec[i][j].first;
				int y=vec[i][k].first;
				ll tx=vec[i][j].second;
				ll ty=vec[i][k].second;
				dis[x][y]=dis[y][x]=min(dis[x][y],tx+ty);
//				cerr<<x<<' '<<y<<' '<<tx<<' '<<ty<<' '<<dis[x][y]<<'\n';
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
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
////			cerr<<i<<' '<<j<<' '<<dis[i][j]<<' '<<dis[j][i]<<'\n';
//		}
//	}
	for(int _=1;_<=q;_++){
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		int cnt1=vec[x].size();
		int cnt2=vec[y].size();
		for(int i=0;i<cnt1;i++){
			for(int j=0;j<cnt2;j++){
				int s=vec[x][i].first;
				ll tx=vec[x][i].second;
				int t=vec[y][j].first;
				ll ty=vec[y][j].second;
				ans=min(ans,dis[s][t]+tx+ty+w[x]+w[y]);
//				cerr<<"_"<<' '<<_<<' '<<s<<' '<<t<<' '<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}