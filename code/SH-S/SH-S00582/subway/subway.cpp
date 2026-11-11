#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,K=5e5+10,inf=1e18+10;
int c,n,m,d,q,w[N],k[N],x,y;
//vector<int> a[N],t[N];
struct line{
	int ind,t;
};
vector<line> dn[K];
struct node{
	int ind,dis;
	bool operator<(const node x)const{
		return x.dis<dis;
	}
};
struct edge{
	int u,v,w,next;
}eg[N];
priority_queue<node> Q;
int head[K],dis[N][N],cnt;
bool vis[N];
void ad(int u,int v,int w){
	eg[++cnt].v=v;
	eg[cnt].w=w;
	eg[cnt].next=head[u];
	head[u]=cnt;
}
void dij(int s){
	dis[s][s]=0;
	Q.push((node){s,0});
	while(!Q.empty()){
		node x=Q.top();
		int u=x.ind;
		Q.pop();
		for(int i=head[u];i;i=eg[i].next){
			int y=eg[i].v;
			//if(vis[y])continue;
			if(x.dis+eg[i].w<dis[s][y]){
				dis[s][y]=x.dis+eg[i].w;
				Q.push((node){y,dis[s][y]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int qwq,awa;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>qwq>>awa;
			dn[qwq].push_back((line){i,awa});
			//a[i].push_back(qwq);
			//t[i].push_back(awa);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<dn[i].size();j++){
			for(int k=j+1;k<dn[i].size();k++){
				ad(dn[i][j].ind,dn[i][k].ind,dn[i][j].t+dn[i][k].t);
				ad(dn[i][k].ind,dn[i][j].ind,dn[i][j].t+dn[i][k].t);
			}
		} 
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dij(i);
	}
	int mins;
	for(int i=1;i<=q;i++){
		mins=inf;
		cin>>x>>y;
		for(int j=0;j<dn[x].size();j++){
			for(int k=0;k<dn[y].size();k++){
				mins=min(mins,w[x]+w[y]+dn[x][j].t+dn[y][k].t+dis[dn[x][j].ind][dn[y][k].ind]);
			}
		}
		cout<<mins<<"\n";
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
