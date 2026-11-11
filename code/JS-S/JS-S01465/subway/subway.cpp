#include<bits/stdc++.h>
using namespace std;//xiongyali
long long c,n,m,d,q,timer=1;
long long w[501005],k[501005];
struct gunmu{
	long long l;
	long long m;
};
vector<gunmu>t[501005];//v,w
struct node{
	long long v,w;
	bool operator <(const node &gm)const{
		return gm.w<w;
	}
};
long long dist[400505];
void bfs(long long u,long long v){ 
	for(int i=0;i<=n+m;i++)dist[i]=114514191;
	dist[u]=0;
	priority_queue<node>q;
	q.push({u,0});
	while(!q.empty()){
		auto uuu=q.top();
		int uu=uuu.v;
		long long nd=uuu.w;
		q.pop();
		if(nd>dist[uu])continue;
		for(auto v:t[uu]){
			long long vi=v.l;
			long long wi=v.m;
			if(dist[uu]+wi<dist[vi]){
				dist[vi]=dist[uu]+wi;
				q.push({vi,dist[vi]});
			}
		}
	}
}	
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			t[x].push_back({i+m,y});
			t[i+m].push_back({x,y});
		}
	}

	while(q--){
		int st,en;
		cin>>st>>en;
		bfs(st,en);
		cout<<dist[en]+w[st]+w[en]<<'\n';
	}
	return 0;
}
