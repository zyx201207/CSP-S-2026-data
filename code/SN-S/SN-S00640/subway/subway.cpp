/*
Xi'an Aerospace City No.1 High School
Senior Grade 1
ZHANG Aoyi
SN-S00640

CCF CSP-S 2026
2026.10.31 14:30-18:30

The High School Affiliated to SNU
R#01-S#47

Answer Disk: D

This is the source code of [T2]
*/
#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>q;
int c,n,m,d,T;
struct edge{
	int u,v;
	int co;
};
vector<edge>G[1000500];
bool vis[1000500];
long long dist[1000500];
queue<edge>q;
void dij(int from,int trag){
	int now=from;
	for(int i=0;i<G[now].size();i++){
		if(vis[G[now][i].v]) continue;
		q.push(G[now][i]);
	}
	while(!q.empty()){
		vis[now]=1;
		//dist[q.front().v]=min(dist[q.front().u]+q.front().co,dist[q.front().v]);
		//cout<<dist[q.front().v]<<"#";
		for(int i=0;i<G[now].size();i++){
			if(dist[G[now][i].u]+G[now][i].co<dist[G[now][i].v]){
				dist[G[now][i].v]=dist[G[now][i].u]+G[now][i].co;
			}
			else{
				if(vis[G[now][i].v]) continue; 
			}
			q.push(G[now][i]);
		}
		now=q.front().v;
		q.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		int w; cin>>w;
		G[i].push_back({i,i+m,w});
		G[i+m].push_back({i+m,i,w});
	}
	//-static-libgcc
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int i1,i2;
			cin>>i1>>i2;
			G[i+2*m].push_back({i+2*m,i1+m,i2});
			G[i1+m].push_back({i1+m,i+2*m,i2});
		}
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<40500;i++){
			dist[i]=2e18,vis[i]=0;
		}
		if(c>=16){
			for(int i=0;i<1000500;i++){
				dist[i]=2e18,vis[i]=0;
			}
		}
		dist[x]=0;
		dij(x,y);
		//for(int i=1;i<=m*2+k;i++) cout<<i<<": "<<dist[i]<<"\n";
		cout<<dist[y]<<"\n";
	}
	return 0;
}
//1.107


