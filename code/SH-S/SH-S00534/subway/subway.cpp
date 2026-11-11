#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
const int MaxN = 5000+10;
const int INF = 1e9+10;
int TESTID,n,m,d;
int wentr[MaxN];
struct Node{
	int v;
	long long w;
	bool operator<(const Node &other)const{return w>other.w;}
};//这里重载小于号还是小于，后面一定要记得使用小根堆greater<int> 
long long dist[MaxN];
bool vis[MaxN];
vector<Node> mp[MaxN*MaxN+2*MaxN+10];
int tot = 0; 
void dijkstra(int start){
	for(int i = 0; i <= tot; i++)vis[i]=false;
	for(int i = 0; i <= tot; i++)dist[i]=INF;
	priority_queue<Node,vector<Node>,less<Node>> pq;
	pq.push({start,0});
	dist[start]=0;
	while(!pq.empty()){
		int u = pq.top().v;
		pq.pop();
//		printf("u=%d\n",u);
		if(vis[u])continue;
		vis[u] = true;
		
		for(auto e: mp[u]){
			int v = e.v;
			long long w = e.w;
			if(dist[v]>dist[u]+w){
				dist[v] = dist[u] + w;
				pq.push({v,dist[v]});
			}
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>TESTID>>n>>m>>d;
	int Q;cin>>Q;
	tot = n + m; 
	for(int i = 1; i <= m; i++)cin>>wentr[i];
	for(int i = 1; i <= n; i++){//对于每一条线路 
		int k;cin>>k;
		for(int j = 1; j <= k; j++){//对于该线路上的站台 
			int u,w;cin>>u>>w;
			//将站台连接到线路上，m+i是第i条线路的超级节点编号 
			//站台编号为 tot
			++tot;
			mp[tot].push_back({m+i,0}) ;//tot -> m+i
			mp[m+i].push_back({tot,0}) ;
			//将站厅本身连接到站台, u->tot
			mp[u].push_back({tot,w}) ;
			mp[tot].push_back({u,w}) ;
		}
	}
//	for(int i = 1; i <= tot; i++){
//		printf("%d can to:",i);
//		for(auto v: mp[i])cout<<"("<<v.v<<' '<<v.w<<")"<< ' ';
//		cout<<'\n';
//	}
	while(Q--){
		int s,t;cin>>s>>t;
		dijkstra(s);
		int res = wentr[s] + dist[t] + wentr[t];
		cout << res << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
