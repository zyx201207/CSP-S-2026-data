#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,di[1010][1010],w[1000010],inq[1000010],dis[1000010],m,s,c,d,Q;
struct edge{
	int v,w;
	bool operator < (const edge &e) const{
		return w<e.w;
	}
};
vector<edge>e[1000010];
priority_queue<edge> q;
void dijk(int s){
	for(int i=1;i<=n+m;i++) dis[i]=1e18,inq[i]=0;
	inq[s]=1;q.push({s,0});dis[s]=0;
	while(!q.empty()){
		int u=q.top().v;q.pop();inq[u]=0;
		for(edge x:e[u]){
			if(dis[u]+x.w<dis[x.v]){
				dis[x.v]=dis[u]+x.w;
				if(!inq[x.v]){
					q.push({x.v,dis[x.v]});
				}
			}
		}	
	}
	for(int i=m+1;i<=m+n;i++) di[s-m][i-m]=dis[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x,y;
			cin>>x>>y;
			e[m+i].push_back({x,y});
			e[x].push_back({i+m,y});
		}
	}
	for(int i=1+m;i<=n+m;i++){
		dijk(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<di[i][j]<<" ";
//		cout<<"\n";
//	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y],mi=1e18;
		for(edge xx:e[x]){
			for(edge yy:e[y])
				mi=min(mi,di[xx.v-m][yy.v-m]+xx.w+yy.w);
		}
		cout<<mi+ans<<"\n";
	}
}