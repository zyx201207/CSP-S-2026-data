#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
vector<pair<int ,int > > pos[M];	//存每个站台经过的线路
vector<int > sta[N];	//存每个线路经过的站台 
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//输入+建图
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int x,t;cin>>x>>t;
			pos[x].push_back({i,t});
			sta[i].push_back(x);
		}
	}
	//对于每个站台，将经过的两个线路连边 
	for(int i=1;i<=m;i++){
		for(auto p1:pos[i]){
			int u=p1.first,t1=p1.second;
			for(auto p2:pos[i]){
				int v=p2.first,t2=p2.second;
				if( u==v )continue;
				dis[u][v]=dis[v][u]=min( dis[u][v],t1+t2 );
			}
		}
	}
	//floyd
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if( i==k )continue;
			for(int j=1;j<=n;j++){
				if( i==j||j==k )continue;
				dis[i][j]=dis[j][i]=min( dis[i][j],dis[k][i]+dis[k][j] );
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int res=0x3f3f3f3f3f3f3f3f;
		for(auto p1:pos[x]){	//枚举两个站点的线路 
			int u=p1.first,t1=p1.second;
			for(auto p2:pos[y]){
			int v=p2.first,t2=p2.second;
				res=min(res,dis[u][v]+t1+t2);
			}
		}
		cout<<w[x]+w[y]+res<<'\n';
	} 
	return 0;
}
/*
你又会为了谁的笑颜而执着呢？ 
*/
