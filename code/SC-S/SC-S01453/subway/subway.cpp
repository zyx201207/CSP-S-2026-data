#include<bits/stdc++.h>
#define int int
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, qu;
int w[N];
int k, u, t;
int x, y;

int inp[N],dis[N]; 
bool vis[N];
vector<pair<int,int>> edge[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
djs(int st,int in[]){
	q.push({0, st});
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[st] = 0;
	while(q.size()){
		int u = q.top().second;
		q.pop();
		vis[u]++;
		for(auto use : edge[u]){
			int v = use.first, w = use.second;
			if(!vis[v]){
				in[v]--;
				dis[v] = min(dis[v], dis[u]+w);
				q.push({in[v],v});
			}
		}
	}
}
//n 线路数    m 地铁站数 

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++){
		cin>>k;
		for(int j = 1; j <= k; j++){
			cin>>u>>t;
			int v = i+m;
			edge[u].push_back({v,t});
			edge[v].push_back({u,t});
			inp[u]++;
			inp[v]++;
		}
	}
	for(int i = 1; i <= qu; i++){
		cin>>x>>y;
		djs(x,inp);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}