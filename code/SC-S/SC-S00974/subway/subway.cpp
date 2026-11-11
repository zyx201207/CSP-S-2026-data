#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
typedef pair<long long,long long> pii;
vector<pii> g[1000005]; //邻接表
int h[10005][10005]; //邻接矩阵
//地铁站数 m
// 出站口 1  2  3  4  5  6  ...  m
//  w[i]  |  |  |  |  |  |  |||  |
// 站台 m+1 m+2 m+3 m+4 m+5 ... 2m
//       |    \   ....
//线路 2m+1-2m+2-...2m+d
//线路 2m+d+1-2m+d+2-...-2m+2d
//最后线路 2m+(n-1)d+1-....-2m+nd
int dp[10005][10005];
int dij(int st,int en){
	int dist[300005];
	bool flag[300005]={0};
	memset(dist,0x3f,sizeof dist);
	priority_queue<pii,vector<pii>,greater<pii> > heap;
	dist[st]=0;
	heap.push({0,st});
	flag[st]=true;
	while(heap.size()){
		int t=heap.top().second;
		heap.pop();
		for(int i=0;i<(int)g[t].size();i++){
			int j=g[t][i].first,w=g[t][i].second;
			if(flag[j]) continue;
			if(dist[j]>dist[t]+w){
				dist[j]=dist[t]+w;
				heap.push({dist[j],j});
				flag[j]=true;
			}
		}
	}
	return dist[en];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){//O(m)
		int x;
		scanf("%d",&x);
		g[i].push_back({m+i,x});
		g[m+i].push_back({i,x});
	}
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		bool f=false;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			g[m+a].push_back({2*m+i*d+j,t});
			g[2*m+i*d+j].push_back({m+a,t});
			if(f){
				g[2*m+i*d+j].push_back({2*m+i*d+j-1,0});
				g[2*m+i*d+j-1].push_back({2*m+i*d+j,0});
			}
			f=true;
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=q;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		if(dp[s][t]<0x3f3f3f3f/2)
			printf("%d\n",dp[s][t]);
		else{
			int res=dij(s,t);
			dp[s][t]=res;
			printf("%d\n",res);
		}
	}
	return 0;
}