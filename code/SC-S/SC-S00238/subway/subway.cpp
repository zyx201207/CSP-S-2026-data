#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5+5,MA=1e9;
struct edge{
	int sta,tim;
};
struct node{
	int u,dis1;
};
vector<edge>g[N];
vector<int>g2[M];
int tl[M],dis[M];
int c,n,m,d,q;
int dij(int s){
	fill(dis+1,dis+m+1,MA);
	dis[s]=0;
	queue<node>q1;
	q1.push({s,0});
	while(!q1.empty()){
		node u1=q1.front();
		for(int i=1;i<=g2[u1.u].size();i++){
			for(int j=1;j<=g[g2[u1.u][i]].size();j++){
				if(dis[u1.u]+g[g2[u1.u][i]][j].tim+g[g2[u1.u][i]][u1.u].tim<dis[g[g2[u1.u][i]][j].sta]){
					dis[g[g2[u1.u][i]][j].sta]=dis[u1.u]+g[g2[u1.u][i]][j].tim+u.tim;
					q1.push({g[g2[u1.u][i]][j].sta,dis[g[g2[u1.u][i]][j].sta]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>tl[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x,y;
			cin>>x>>y;
			tl[x]=y;
			g[i].push({x,y});
			g2[x].push(i)
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int k=tl[x]+tl[y];
		dij(x);
		cout<<dis[y]<<endl;
	}
}