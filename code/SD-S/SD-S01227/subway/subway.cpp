#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=505,M=500005;
/*struct Node {
	int u,dis;
	bool operator <(const Node& other)const {
		return dis<other.dis;
	}
};*/
vector<pii> edge[N];
int c,n,m,d,q,k;
int x,y;
//int dis[M];
//bool outQ[M];
int W[M];
int T[N][M];
int a[N][M];
/*void djk() {
	priority_queue<Node>pq;
	memset(dis,0x3f,sizeof dis);
	memset(outQ,0,sizeof outQ);
	dis[1]=0;
	pq.push({1,0});
	while(!pq.empty()) {
		Node top=pq.top();
		int u=top.u;
		if(outQ[u])continue;
		for(auto i:edge[u]) {
			int v=i.first,w=i.second;
			if(dis[u]+w<=dis[v]) {
				dis[v]=dis[u]+w;
				if(!outQ[v]) {
					pq.push({v,w});
					outQ[v]=1;
				}
			}
		}
	}
}*/
int dis[M];
int ans;
void dfs(int u,int cost,int path,int num) {
	//目前节点 花费 路径号 节点号
	//dis[u]=min(dis[u],cost+)
	//第一种顺着线路往下走
	if(u==y) {
		ans=min(ans,cost+W[u]);
		return ;
	}
	if(num+1<=k)dfs(a[path][num+1],cost,path,num+1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k-1; j++) {
			if(a[i][j]==u) {
				dfs(a[i][j+1],cost+T[u][a[i][j+1]]+T[a[i][j+1]][a[i][j+1]],i,j);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>W[i];
	}
	cin>>k;
	for(int i=1; i<=k; i++) {
		cin>>a[i][k]>>T[i][k];
	}
	cin>>q;
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		memset(dis,0x3f,sizeof dis);
		ans=0x3f3f3f3f;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=k-1; j++) {
				if(a[i][j]==x) {
					dfs(x,W[x],i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
