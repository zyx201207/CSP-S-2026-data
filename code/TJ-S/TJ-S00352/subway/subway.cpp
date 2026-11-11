#include <bits/stdc++.h>
using namespace std;
const int N=500;
const int M=5*1e5+10;
int c,n,m,d,qq;
int w[N];
struct Node{
	int id,w;
	Node(){};
	Node (int a,int b){
		id=a,w=b;
	}
	bool operator < (const Node &b)const{
		return w>b.w;
	}
};

int dis[N+M],vis[N+M];
vector<Node> e[N+M];
priority_queue<Node> q;

int dijsktra (int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(Node(x,0));
	dis[x]=0;
	while (!q.empty()){
		Node now=q.top();q.pop();
		int u=now.id,w=now.w;
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0;i<e[u].size();i++){
			int v=e[u][i].id;
			if (dis[v]>dis[u]+e[u][i].w){
				dis[v]=dis[u]+e[u][i].w;
				q.push(Node(v,dis[v]));
			}
		}
	}
	return dis[y];
}

signed main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> qq;
	for (int i=1;i<=m;i++) cin >> w[i];
	int cnt=m;
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		cnt++;
		for (int j=1;j<=k;j++){
			int x,t;
			cin >> x >> t;
			e[cnt].push_back(Node(x,t));
			e[x].push_back(Node(cnt,t));
		}
	}
	
	while (qq--){
		int x,y;
		cin >> x >> y;
		int ans=w[x]+w[y]+dijsktra(x,y);
		cout << ans << '\n';
	}
	return 0;
}
