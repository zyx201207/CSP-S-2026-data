#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int dis[500005],w[500005],xian[505],xian1[505];
struct egde{
	int v,xi;
};
vector<egde>G[500005];
int g[500005][505];
bool f[500005];
struct node{
	int dis,v;
	bool operator >(const node&other)const{
		return dis>other.dis;
	} 
};
bool jj[505];
priority_queue<node,vector<node>,greater<node> > pq;
void dij(int s){
	memset(dis,0x7f,sizeof dis);
	dis[s]=0;
	pq.push({0,s});
	memset(f,0,sizeof f);
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		if(f[u]==1)continue;
		f[u]=1;
		memset(jj,0,sizeof jj);
		for(auto d:G[u]){
			int v=d.v,xi=d.xi;
			int w=g[v][xi];
			if(jj[xi]==0)w+=g[u][xi],jj[xi]=1;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		int k,o,a,t;
		cin>>k>>o;
		for(int j=1;j<=k-1;j++){
			cin>>t>>a;
			G[o].push_back({a,i});
			G[a].push_back({o,i});
			g[o][i]=t;
			o=a;
		}
		cin>>t;
		G[o].push_back({a,i});
		G[a].push_back({o,i});
		g[o][i]=t;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}//rp++;
	return 0;
}
