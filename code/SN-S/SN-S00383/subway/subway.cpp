#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
const int inf=1e18;
int C,D,Q;
int n,m,w[M];
struct node{
	int a,t;
};
vector<node> v[N];
vector<node> z[M];
int dis[N][N];
signed main(){
	O1145 O1919
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dis[i][j]=inf;
	for(int i=0;i<N;i++)dis[i][i]=0;
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int K;cin>>K;
		while(K--){
			int aa,tt;cin>>aa>>tt;
			v[i].push_back({aa,tt});
			z[aa].push_back({i,tt});
		}
	}
	//不是哥们，换乘是什么玩意？？？ 
	for(int i=1;i<=m;i++){
		for(int xx=0;xx+1<z[i].size();xx++){
			for(int yy=xx+1;yy<z[i].size();yy++){
				node x=z[i][xx],y=z[i][yy];
				dis[x.a][y.a]=dis[y.a][x.a]=min(dis[x.a][y.a],x.t+y.t);
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
	while(Q--){
		int s,e;cin>>s>>e;
		int ans=1e18;
		for(int xx=0;xx<z[s].size();xx++){
			int x=z[s][xx].a,xt=z[s][xx].t;
			for(int yy=0;yy<z[e].size();yy++){
				int y=z[e][yy].a,yt=z[e][yy].t;
				ans=min(ans,w[s]+xt+dis[x][y]+yt+w[e]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
