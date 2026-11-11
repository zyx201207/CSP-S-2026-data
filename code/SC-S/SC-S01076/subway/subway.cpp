/*
给个形式化又咋了？

给你 m 个二元点 (first,second)

其中 first <--> second 有一条长度为 w_i 的边

给你 n 条便捷路径，第 i 条经过 k_i 个点，与过的点的 second 有一条长度为 t_i,j 的边，便捷路径之间长度为 0.

限制每个点只有 d 条路径通过，保证图联通

q 次询问点 x 的 first 到点 y 的 first 的最短路长度(不是哥们，那第一种路有啥用)

n\leq 500,m\leq \sum k\leq5e5,d\leq 20,q\leq 1e5
*/
/*
这题何意味呢？

变成 w_x+w_y + else

从 d 入手，感觉是什么奇怪的复杂度

一个显然的想法是从 n 入手，建出 n 个点，每个点相当于连向 k 个点边权各异

卧槽了老哥！这是个二分图，考虑二分图的性质，我们直接建 n^2 条边去跑最短路，然后 O(d^2) 处理每次询问不久行了吗！

复杂度 O(n^3 + qd^2)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
const int N=505;
const int inf=5e15+7;
int n,m,d,q;
int W[M];
int dis[N][N];
vector<pair<int,int>>mp[M];
inline void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;cin>>x>>w;
			mp[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<(int)mp[i].size();j++){
			int x=mp[i][j].first,w=mp[i][j].second;
			for(int k=0;k<j;k++){
				int y=mp[i][k].first;w+=mp[i][k].second;
				dis[x][y]=min(dis[x][y],w);
				dis[y][x]=min(dis[y][x],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]>=inf||i==k)continue;
			for(int j=1;j<=n;j++){
				if(i!=j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=inf;
		for(auto asd:mp[x]){
			int x=asd.first,w=asd.second;
			for(auto dsa:mp[y]){
				int y=dsa.first,t=dsa.second;
				ans=min(ans,dis[x][y]+w+t);
			}
		}
		ans+=W[x]+W[y];
		cout<<ans<<'\n';
	}
}
signed main (){
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int cid,Case=1;cin>>cid;
	while(Case--)solve();
	return 0;
}