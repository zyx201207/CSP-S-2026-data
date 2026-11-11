#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,D=30,Q=1e5+10;
int c,n,m,d,q,w[M],tt[N][M],x[Q],y[Q],k[N],ans=-1;
vector<int> a[N],jg[M];
bool vis[M];
struct Node{
	int x;
	int t;
	int now;
	bool operator<(const Node &b){
		return t>b.t;
	}
};bool operator<(const Node &a,const Node &b){
	return a.t>b.t;
}
set<Node> gg;
void bfs(int st,int ed){
	priority_queue<Node> pq;
	pq.push({st,0,0});
	while(!pq.empty()){
		auto pp=pq.top(); pq.pop();
		cout<<gg.size()<<' '<<gg.count(pp)<<endl;
		if(gg.count(pp)>0) continue;
		gg.insert(pp);
		int x=pp.x,t=pp.t,nw=pp.now;
		vis[x]=true;
		if(x==ed&&nw==0){
			ans=t;
			return;
		}
		if(nw!=0) for(int j:a[nw]) if(!vis[j]){
			pq.push({j,t,nw});
		}
		for(int i:jg[x]){
			if(i!=nw){
				if(nw==0){
					pq.push({x,t+w[x]+tt[i][x],i});
				}
				else if(i==0){
					pq.push({x,t+tt[nw][x]+w[x],0});
				}
				else{
					pq.push({x,t+tt[nw][x]+tt[i][x],i});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		jg[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>tt[i][x];
			a[i].push_back(x),jg[x].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		cin>>x[i]>>y[i];
		bfs(x[i],y[i]);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
*/