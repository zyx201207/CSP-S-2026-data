#include<bits/stdc++.h>
using namespace std;
int w1[500010];
struct node{
	int v;
	long long w;
};
vector<node> g[500510];
long long dis[510][510];
bool vis[510];
int c,n,m,d,qq;
int start,endd;
long long ans;
int uu,vv,ww;
int kk,i,j,ii;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
void dij(int start,int id){
	memset(vis,0,sizeof vis);
	q.push({0,start});
	dis[id][start]=0;
	for(i=1;i<=id;i++){
		dis[id][i]=dis[i][start];
	}
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.second]==1) continue;
		vis[u.second]=1;
//		siz++;
		for(i=0;i<(int)(g[u.second].size());i++){
			node v1=g[u.second][i];
			for(j=0;j<(int)(g[v1.v].size());j++){
				node v=g[v1.v][j];
				if(dis[id][v.v]>u.first+v.w+v1.w){
					dis[id][v.v]=u.first+v.w+v1.w;
					q.push({dis[id][v.v],v.v});
				}
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(i=1;i<=m;i++){
		cin>>w1[i];
	}
	for(i=1;i<=n;i++){
		cin>>kk;
		for(j=1;j<=kk;j++){
			cin>>vv>>ww;
			vv+=n;
			g[i].push_back({vv,ww});
			g[vv].push_back({i,ww});
		}
	} 
	memset(dis,0x3f,sizeof dis);
	for(ii=1;ii<=n;ii++){
		dij(ii,ii);
	}
//	cout<<siz<<"\n";
	while(qq--){
		cin>>start>>endd;
		ans=1e18;
		start+=n;
		endd+=n;
		for(uu=0;uu<(int)(g[start].size());uu++){
			for(vv=0;vv<(int)(g[endd].size());vv++){
				i=g[start][uu].v,j=g[endd][vv].v;
				ans=min(ans,dis[i][j]+g[start][uu].w+g[endd][vv].w);
			}
		}
		cout<<ans+w1[start-n]+w1[endd-n]<<"\n";
	}
	return 0;
}