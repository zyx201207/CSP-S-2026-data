#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1010],vis[50010],a[500010],b[500010],p[1010],dis[510][50010];
struct Node{
	long long v,w;
};
vector <Node>e[50010];
void dijk(int s){
	priority_queue <pair<int,int>> pq;
	for(int i=1;i<=m*(d+1);i++)vis[i]=0,dis[s][i]=1<<31;
	pq.push({0,s});
	dis[s][s]=0;
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		vis[u]=1;
		for(auto v:e[u]){
			if(!vis[v.v]&&dis[s][v.v]<dis[s][u]+v.w){
				dis[s][v.v]=dis[s][u]+v.w;
				pq.push({-dis[s][v.v],v.v});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>b[j]; 
		for(int j=1;j<k;j++){
			e[m*(p[a[j]]+1)+a[j]].push_back({m*(1+p[a[j+1]])+a[j+1],0});
			e[m*(1+p[a[j+1]])+a[j+1]].push_back({m*(p[a[j]]+1)+a[j],0});
		}
		for(int j=1;j<=k;j++){
			e[a[j]].push_back({m*(p[a[j]]+1)+a[j],b[j]});
			e[m*(p[a[j]]+1)+a[j]].push_back({a[j],b[j]});
		}
		for(int j=1;j<=k;j++)p[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		dijk(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}