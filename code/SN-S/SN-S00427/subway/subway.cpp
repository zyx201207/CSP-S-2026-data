#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10;

struct edge{
	int v,w;
	int id;
};

bool operator >(edge x,edge y){
	return x.w<y.w;
}

int c,n,m,d,q;
int w[M];
vector<edge> G[M];
vector<int> t[550];
vector<int> sta[M]; //i站点被哪些线路经过 

int dis[M][400];
bool vis[M][550];
map<int,int> iid[M];

void dij(int s,int e){
	
	priority_queue<edge,vector<edge>,greater<edge>> q;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			dis[i][j]=1e18;
			vis[i][j]=0;
		}
	}
	
	for(auto v : sta[s]){
		q.push({s,0,v});
	}
	
	while(!q.empty()){
		auto tmp=q.top(); q.pop();
		int u=tmp.v,idu=tmp.id;
		if(vis[u][idu]) continue;
		vis[u][idu]=1;
		
		for(auto vv : G[u]){
			int v=vv.v,id=vv.id;
			if(idu==id){
				if(dis[u][id]<dis[v][id]){
					dis[v][id]=dis[u][id]+1;
					q.push({v,dis[v][id],id});
				}
			}
			else{
				if(dis[u][idu]+t[idu][iid[idu][u]]+t[id][iid[id][v]]<dis[v][id]){
					dis[v][id]=dis[u][idu]+t[idu][iid[idu][u]]+t[id][iid[id][v]];
					q.push({v,dis[v][id],id});
				}
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[e][i]);
	}
	cout<<ans+w[e]<<"\n";
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	int lasta=0;
	for(int i=1;i<=n;i++){
		int ki; cin>>ki;
		for(int j=1;j<=ki*2;j++){
			int aij,tij; cin>>aij>>tij;
			if(j==1){
				G[0].push_back({aij,tij+w[aij],0});
			}
			else{
				G[lasta].push_back({aij,0,i});
			}
			t[i].push_back(tij);
			sta[aij].push_back(i);
			iid[i][aij]=j;
			lasta=aij;
		}
	}
	
	while(q--){
		int s,e; cin>>s>>e;
		dij(s,e);
	}
	
	return 0;
	
}
