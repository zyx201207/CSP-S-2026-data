#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[1500005];
struct edge{
	int to,w;
};
vector<edge>e[1500005];
bool relax(int u,int v,int w){
	if(f[v]>f[u]+w){
		f[v]=f[u]+w;
		return 1;
	}
	return 0;
}
void init(int s){
	memset(f,0x7f,sizeof(f));
	f[s]=0;
}
struct info{
	int id,w;
	bool operator<(const info&a)const{
		return w>a.w;
	}
};
priority_queue<info>qu;
bool vis[1500005];
void dijk(int s){
	init(s);
	qu.push({s,0});
	while(!qu.empty()){
		info tp=qu.top();
		qu.pop();
		int idd=tp.id;
		if(vis[idd])continue;
		vis[idd]=1;
		for(int i=0;i<e[idd].size();i++){
			if(relax(idd,e[idd][i].to,e[idd][i].w&&!vis[e[idd][i].to])){
				qu.push({e[idd][i].to,f[e[idd][i].to]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int w;
		cin>>w;
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int nxt=0;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			e[a-1+m].push_back({a-1+2*m,t});
			e[a-1+2*m].push_back({a-1+m,t});
			if(j!=0){
				e[a-1+2*m].push_back({nxt,0});
				e[nxt].push_back({a-1+2*m,0});
			}
			nxt=a-1+2*m;
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		cin>>u>>v;
		dijk(u-1);
		cout<<f[v-1]<<'\n';
//		cout<<i<<'\n';
//		for(int i=0;i<3*m;i++)cout<<f[i]<<' ';
//		cout<<'\n';
	}
	return 0;
}
