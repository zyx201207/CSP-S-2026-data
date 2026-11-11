//subway.cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;
const ll inf=1e18;
int T,n,m,q,d;
struct node{
	int u,w;
	bool operator<(const node &B) const{
		return w>B.w;
	}
};
/*struct node{
	int u,v,w;
};*/
vector<node> e[N];
ll dis[N][N];
bool vis[N];
void dij(int s){
	memset(vis,0,sizeof(vis));
	priority_queue<node> pq;
	dis[s][s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().u;
		pq.pop();
		for(auto x:e[u]){
			int v=x.u,w=x.w;
			//cout<<v<<" "<<u<<" "<<w<<"\n";
			if(dis[s][v]>dis[s][u]+w){
				//cout<<dis[s][v]<<" "<<dis[s][u]<<"\n"; 
				dis[s][v]=dis[s][u]+w;
				if(!vis[v]){
					pq.push({v,w});
					vis[v]=1;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	for(int i=1;i<=N-5;i++){
 		for(int j=1;j<=N-5;j++)
 			dis[i][j]=inf;
	}
 	cin>>T>>n>>m>>d>>q;
 	//1~m: 地铁站
	// m+1~2m 站厅
	// 2m~2m+n 线路 
 	for(int i=1;i<=m;i++){
 		int w;cin>>w;
 		e[i].push_back({i+m,w});
 		e[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a+m].push_back({2*m+i,t});
			e[2*m+i].push_back({a+m,t});
		}
	}
	while(q--){
		int S,E;
		cin>>S>>E;
		if(dis[S][E]!=inf)
			cout<<dis[S][E]<<"\n";
		else{
			dij(S);
			cout<<dis[S][E]<<"\n";
		}
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/