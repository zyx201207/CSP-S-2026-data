#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,u,v,ai,ti;
const int M=5e5+5;
const int N=505;
unordered_map<int,int> mp[M];
int w[M],k[N];
ll t[M][30];
ll dis[M]; 
struct edge{
	int id,nex;
	ll t;
};
vector<edge> pas[M];

struct node{
	int u,id;
	ll s;
};
queue<node> qe;
long long bfs(int u,int v,int q){
	for(int i=1;i<=m;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	for(auto i:pas[u]){
		dis[u]=min(dis[u],t[u][mp[u][i.id]]);
		qe.push({u,i.id,t[u][mp[u][i.id]]});
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	while(!qe.empty()){
		node h=qe.front();
		qe.pop();
		if(h.u==v){
			ans=min(ans,dis[v]+t[v][mp[v][h.id]]);
		}
		for(auto i:pas[h.u]){
			if(h.id==i.id){
				dis[i.nex]=min(h.s,dis[i.nex]);
				qe.push({i.nex,i.id,h.s});
			}
			else{
				dis[i.nex]=min(dis[i.nex],h.s+t[h.u][mp[i.nex][h.id]]+t[h.u][mp[i.nex][i.id]]);
				qe.push({i.nex,i.id,h.s+t[h.u][mp[i.nex][h.id]]+t[h.u][mp[i.nex][i.id]]});
			}
			
		}
	}
	return ans+w[u]+w[v];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,0x3f,sizeof t);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int la=0;
		for(int j=1;j<=k[i];j++){
			cin>>ai>>ti;
			pas[la].push_back({i,ai,ti});
			la=ai;
			mp[ai][i]=j;
			t[ai][j]=ti;
		}
	}
	while(q--){
		cin>>u>>v;
		cout<<bfs(u,v,q)<<'\n';
	}
	return 0;
}

