#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10,M=5e5+10;
int C,n,m,d,q,w[M],ans;
int sk[N];
//vector<int> a[N],t[N];//xianlu
vector<int> za[M],zt[M];//zhanting

int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>sk[i];
		for(int j=1;j<=sk[i];++j){
			int x,y;
			cin>>x>>y;
//			a[i].push_back(x);
//			t[i].push_back(y);
//			for(int k=0;k<j-1;++k){
//				int tt=min(dis[x][a[i][k]],y+t[i][k]);
//				dis[x][a[i][k]]=dis[a[i][k]][x]=tt;
//			}
			za[x].push_back(i);
			zt[x].push_back(y);
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<za[i].size();++j){
			for(int k=0;k<j;++k){
				int xx=za[i][j],yy=za[i][k];
				int tt=min(dis[xx][yy],zt[i][j]+zt[i][k]);
				dis[xx][yy]=dis[yy][xx]=tt;
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j) cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<za[x].size();++i){
			for(int j=0;j<za[y].size();++j){
				int xx=za[x][i],yy=za[y][j];
				ans=min(ans,dis[xx][yy]+zt[x][i]+zt[y][j]);
//				cout<<xx<<' '<<yy<<' '<<ans<<'\n';
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
