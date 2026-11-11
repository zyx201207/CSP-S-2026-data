#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
/*
或许是图论题，起点和终点最后再算也不影响
特殊点：
1：d很小，最多只有20，也就是说每个换乘站的线会比较少
2：地铁线路最多只有500条
要求总步行时间最小，不一定是坐地铁的总时间最小
是否可以预处理？
定义到达每个点的时间为到达每个站站厅的时间
如果从起点开始dij，总复杂度为n^2logn，TLE
但是有个性质：
同一条线上坐地铁不花时间，那么，可否预处理从a号线到b号线所需
的最短步行时间，那么，假设t[i][j]表示从i号线转到j号线的最短
步行时间，则有：
一：循环st的所有线路i，ed的所有线路j --> 400
二：答案为min（t[i][j])+起点站厅+起点线路站台+终点站厅+终点线路站台
预处理可以考虑floyd -> n^3
输出为 -> 400*q ->4e7
可以通过
考虑如何建图：
当两条线路相交时可以看作有一条边，权值为对应到站厅时间之和
用二维数组方便取min与O(1)查询
*/

int C,n,m,dmax,Q;
ll w[N],dis[505][505];
struct node{
	int line;
	ll d;
};
vector<node> p[N];

void biuld(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=p[i].size();
		if(sz==1) continue;
		for(int j=0;j<sz;j++){
			int u=p[i][j].line;
			ll w=p[i][j].d;
			for(int k=j+1;k<sz;k++){
				int v=p[i][k].line;
				w+=p[i][k].d;
				dis[u][v]=min(w,dis[u][v]);
				dis[v][u]=min(w,dis[v][u]);
			}
		}
	}
	return;
}

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>dmax>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int kx;
		cin>>kx;
		for(int j=1;j<=kx;j++){
			int x;
			ll y;
			cin>>x>>y;
			p[x].push_back({i,y});
			
		}
	}
	biuld();
	floyd();
	while(Q--){
		int st,ed;
		cin>>st>>ed;
		int stsz=p[st].size();
		int edsz=p[ed].size();
		ll ans=w[st]+w[ed],minn=1e18;
		for(int i=0;i<stsz;i++){
			for(int j=0;j<edsz;j++){
				int u=p[st][i].line;
				int v=p[ed][j].line;
				minn=min(minn,dis[u][v]+p[st][i].d+p[ed][j].d);
			}
		}
		ans+=minn;
		cout<<ans<<'\n';
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