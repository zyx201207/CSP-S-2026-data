#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i<=b;i++)
#define ll long long
using namespace std;
struct edge{
	int v,w;
};
vector<edge> g[1500005];//不够用，后面再算 
int idx,dis[1500005];
bool vis[1500005];
struct node{
	int dis,u;
	bool operator>(const node &a)const {return dis>a.dis;}
};
priority_queue<node,vector<node>,greater<node>> qq;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	qq.push({0,s});
	while(!qq.empty()){
		int u = qq.top().u;
		qq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto it:g[u]){
			int v = it.v,w = it.w;
			if(dis[v]>dis[u]+w){
				dis[v] = dis[u]+w;
				qq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	For(i,1,m){
		int w;
		cin>>w;
		g[i].push_back({m+i,w});
		g[m+i].push_back({i,w});
	}//i->地铁口，m+i->站厅 ,2*m+i->线路
	For(i,1,n){
		int k;
		cin>>k;
		For(j,1,k){
			int a,t;
			cin>>a>>t;
			g[m+a].push_back({2*m+i,t});
			g[2*m+i].push_back({m+a,t});
			/*if(j>1){
				g[2*m+idx].push_back({pre,0});
				g[pre].push_back({2*m+idx,0});
			}
			pre = 2*m+idx;*/
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/


