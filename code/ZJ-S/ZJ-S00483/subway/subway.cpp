#include <bits/stdc++.h>
#define int long long
#define INF 0x7f7f7f7f7f7f7f7f
using namespace std;

int a[500010];
int t[500010];
int w[500010];
int dis[1010][1010];
int vis[1010];
int head[1010];
int tt;

struct node{
	int u;
	int w;
	bool operator < (const node & b) const{
		return w<b.w;
	}
	bool operator > (const node & b) const{
		return w>b.w;
	}
};
struct edge{
	int to;
	int w;
	int nxt;
}e[500010];

void add_edge(int u, int v, int w){
	
	e[++tt]={v,w,head[u]};
	head[u]=tt;
	
	return ;
}

void Dijkstra(int s){
	
	memset(vis,0,sizeof vis);
	priority_queue<node,vector<node>,greater<node>> q;
	q.push({s,0});
	dis[s][s]=0;
	
	while(!q.empty()){
		int u=q.top().u;
		int step=q.top().w;
		q.pop(); 
		if(step>dis[s][u])continue;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].to;
			int w=e[i].w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
	
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	memset(dis,0x7f,sizeof dis);
	memset(head,-1,sizeof head);
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		int l;
		cin >> l;
		for(int j=1;j<=l;j++){
			cin >> a[j] >> t[j];
		}
		for(int j=1;j<=l;j++){
			for(int k=1;k<=l;k++){
				if(j==k)continue;
				dis[a[j]][a[k]]=dis[a[k]][a[j]]=min(dis[a[j]][a[k]],t[j]+t[k]);
			} 
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			if(dis[i][j]==INF)continue;
			add_edge(i,j,dis[i][j]);
		}
	}
	
	memset(dis,0x7f,sizeof dis);
	
	for(int i=1;i<=m;i++){
		Dijkstra(i);
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << dis[x][y]+w[x]+w[y] << endl;
	}
	
	return 0;
}

