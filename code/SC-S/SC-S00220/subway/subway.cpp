/*
呵呵，读题读了1小时
没读懂
甚至无法看透是什么算法
呵呵
noi你就写你的作文去吧 
哦哦哦懂了，原来t是边权
。。，， 
就是这个复杂度嘛。
 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int w[N],k[M],a[M][M],t[M][M],dis[N],vis[N];
struct node {
	int v,w;
};
vector<node> g[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i) {
		cin>>k[i];
		for(int j=1;j<=k[i];++j) {
			cin>>a[i][j]>>t[i][j];
			g[i].push_back({a[i][j],t[i][j]});
		}
	}
	while(q--) {
		int s,e;
		cin>>s>>e;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dis[s]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		q.push({0,s});
		while(!q.empty()) {
			int u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto cur:g[u]) {
				int v=cur.v,w=cur.w;
				if(dis[u]+w+t[u][u]<dis[v]) {
					dis[v]=dis[u]+w+t[u][u];
					q.push({dis[v],v});
				}
			}
		}
		cout<<dis[e]+w[s]+w[e]<<'\n';
	}
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
4 3 2 5 100 3 6 6
1 6
2 3
*/