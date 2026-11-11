//输入：c测试点、n铁路数、m站数、d每个站最多的线数、询问数
//每个站出去的时间 * m
//每条铁路经过的站点和每个站点到站厅的时间
//q 个查询 
//注意到直接按题意建图边的数量太多了（n^2级别）
//可以考虑将每条线路作为一个点，使用邻接矩阵储存（n<500） ，转乘作为边
//考虑使用全源最短路预处理每两条线路之间的最短距离
//最后对于每个询问直接分别枚举起点和终点每个经过的线路寻找最短路！！！ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 10000000000000000
const int N=1005;
const int M=1000005;

int c,n,m,d,q;
int w[M];
vector <pii> g[M];
int mp[N][N];

inline void min_(int &a,int b){a=min(a,b);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int a,t;k--;){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;i++){
		for(pii u:g[i]){
			for(pii v:g[i]){
				min_(mp[u.fi][v.fi],u.se+v.se);
			}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(pii j:g[i]){
//			cout<<j.fi<<' '<<j.se<<'\n';
//		}
//	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				min_(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<mp[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int x,y;q--;){
		cin>>x>>y;
		int ans=INF;
		for(pii i:g[x]){
			for(pii j:g[y]){
				min_(ans,i.se+mp[i.fi][j.fi]+j.se);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
