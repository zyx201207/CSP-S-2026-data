#include<bits/stdc++.h>
using namespace std;
struct T{
	int to,w;
};
bool operator<(T x,T y){
	return x.w>y.w;
}
int c,n,m,d,q;
int w[20005];
vector<T>g[1000005];
int dis[20005][20005];
void dist(int s){
	priority_queue<T>q;
	int vis[20005]={0};
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().to;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto c:g[u]){
			int v=c.to,len=c.w;
			if(dis[s][v]>dis[s][u]+len){
				dis[s][v]=dis[s][u]+len;
				q.push({v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].push_back({i+m,w[i]});
		g[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,len;
			cin>>to>>len;
			g[2*m+i].push_back({to+m,len});
			g[to+m].push_back({2*m+i,len});
		}
	}
	for(int i=1;i<=m;i++){
		dist(i);
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dis[s][t]<<"\n";
	}
}