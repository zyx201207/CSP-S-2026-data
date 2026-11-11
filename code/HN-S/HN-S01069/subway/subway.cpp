#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+510,NN=510,inf=1e17;
struct gm{
	int to,w;
};
vector<gm> frm[N];
int way[NN][NN];
struct node{
	int id,w;
	bool operator >(const node & other)const {return w>other.w;}
};
priority_queue<node,vector<node>,greater<node> > q;
int dis[NN];
bool vis[NN];
int s;
//
int n,m,d,c,Q,dcnt;
int derta[N];
int resl[NN][NN];
//
void init(){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	q.push({s,0});dis[s]=0;
} 
void dij(){
	init();
	while(!q.empty()){
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			if(vis[v])continue;
			if(dis[v]>dis[u]+way[u][v]){
				dis[v]=dis[u]+way[u][v];
				q.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		resl[s][i]=dis[i];
	}
}
signed main(){
	//张竞兮 冷静下来 我相信你 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)way[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>derta[i];
	for(int i=1;i<=n;i++){
		int tk=0,x,y;cin>>tk;
			for(int j=1;j<=tk;j++){
				cin>>x>>y;
				for(auto v:frm[x]){
					way[i][v.to]=min(way[i][v.to],v.w+y);
					way[v.to][i]=way[i][v.to];
				}
				frm[x].push_back({i,y});
			}
	}
	for(int i=1;i<=n;i++){
		s=i;dij();
	}
	while(Q--){
		int xx,yy,aans=inf;cin>>xx>>yy;
		for(auto u:frm[xx]){
			for(auto v:frm[yy]){
				aans=min(aans,resl[v.to][u.to]+v.w+u.w);
			}
		}
		cout<<(aans+derta[xx]+derta[yy])<<"\n";
	}
	return 0;
}
