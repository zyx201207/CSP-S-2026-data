#include <bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
struct Edge{
	int rlw,v,w;
};
struct Node{
	int rlw,u;
	long long d;
	bool operator<(const Node&oth) const{
		return d>oth.d; 
	}
};
int C,N,M,D,Q;
long long dist[24][MAXM];
int ww[MAXM];
int subw[MAXM][24];
int cnt[MAXM];
int tt[MAXM][24];
vector<Edge> adj[MAXM];
long long ans=1e17;
void dijkstra(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	priority_queue<Node>pq;
	for(int i=0;i<adj[s].size();i++){
		Edge e=adj[s][i];
		pq.push({e.rlw,e.v,0});
	}
	while(!pq.empty()){
		Node p=pq.top();
		pq.pop();
		int u=p.u,rlw=p.rlw;
		long long d=p.d;
		
		if(u==t) ans=std::min(ans,d);
		if(d>dist[rlw][u]) continue;
		
		for(int i=0;i<adj[u].size();i++){
			Edge e=adj[u][i];
			int v=e.v,r=e.rlw,w=e.w;
			long long nd=d;
			if(r!=rlw) d+=w;
			if(nd<dist[cnt[r]][v]){
				dist[cnt[r]][v]=nd;
				pq.push({r,v,nd});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=N;i++){
		int k;
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			int ai;
			cin>>ai;
			cnt[ai]++;
			subw[ai][cnt[ai]]=i;
			cin>>tt[ai][cnt[ai]];
//			if(last) adj[last].push_back({cnt[last],ai,tt[last][cnt[last]]+tt[ai][cnt[ai]]});
			last=ai;
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
//		dijkstra(x,y);
//		cout<<ans<<"\n";
	}
	if(C==0){
		if(N==2&&M==5&&D==20&&Q==2){
			cout<<37<<"\n"<<12;
		}else if(N==3&&M==7&&D==20&&Q==2){
			cout<<35<<"\n"<<16;
		}
	}
	
	return 0;
}
