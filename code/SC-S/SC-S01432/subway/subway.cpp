#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000010];
int k[100010];
int x,y;
struct node{
	int id;
	int sz;
};
vector<node>p[505];
int dp[1010][1010];
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e9;
		}
		dp[i][i]=0;
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			p[x].push_back({i,y});
			
		}	
	}
	for(int i=1;i<=m;i++){
		for(int l=0;l<p[i].size();l++){
			for(int r=l;r<p[i].size();r++){
				int u=p[i][l].id;
				int v=p[i][r].id;
				dp[u][v]=min(dp[u][v],p[i][l].sz+p[i][r].sz);
				dp[v][u]=min(dp[u][v],p[i][l].sz+p[i][r].sz);
			}
		}
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	for(int k=1;k<=q;k++){
		cin>>x>>y;
		int mi=1e9;
		for(int i=0;i<p[x].size();i++){
			for(int j=0;j<p[y].size();j++){
				int u=p[x][i].id;
				int v=p[y][j].id;
				//cout<<u<<" "<<v<<" "<<dp[u][v]<<" "<<w[x]<<" "<<w[y]<<" "<<p[x][i].sz<<" "<<p[y][k].sz<<endl;
				mi=min(mi,dp[u][v]+w[x]+w[y]+p[x][i].sz+p[y][j].sz);
			}
		}
		cout<<mi<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
题意转化：给你一张图求图中任意两点的最短距离 
观察数据发现站数 m 和 询问次数 q 都比较大
出现 d 则它肯定是破局关键 
只有 n和d 较小，虑从 n 入手 我们不妨将每条地铁线当作图中的端点
在求地铁站之间的最小值时
找到与地铁站的相连的地铁线路 
看每条线路之间的最小值

复杂度 d*d*q
预处理每条线路之间的最小值 
考虑多次单源最短路 复杂度 n*n*logn 
对于两条相邻的铁路线 枚举每个站点所连接的铁路 
因为 k[i]的和小于 500005

算法 小根堆+ 
*/