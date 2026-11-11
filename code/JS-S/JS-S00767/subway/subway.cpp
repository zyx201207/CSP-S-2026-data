#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=501,M=50005,INF=1e9;
int a[N][M],t[N][M];
int w[M];
int k[N];
ll dis[10005][10005];
bool vis[10005][10005];
bool vvis[M];
int c,n,m,d,q;
int tot=1;
ll ans;
struct nod{
	ll v,w;
	bool operator <(const nod &o)const{
		return o.w<w;
	}
};
vector <nod> G[M];
priority_queue <nod> pq;
void pprint(){
	for(int i=1;i<=m+tot-1;i++){
		int siz=G[i].size();
		cout<<i<<":"<<endl;
		for(int j=0;j<siz;j++){
			cout<<G[i][j].v<<' '<<G[i][j].w<<endl;
		}
		cout<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+5;i++){
		for(int j=1;j<=m+5;j++){
			dis[i][j]=INF;
			vis[i][j]=0;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back((nod){m+tot,t[i][j]});
			G[m+tot].push_back((nod){a[i][j],t[i][j]});
			if(j!=k[i]){
				G[m+tot].push_back((nod){m+tot+1,0});
				G[m+tot+1].push_back((nod){m+tot,0});
			}
			tot++;
		}
	}
	//pprint();
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		if(vvis[x]){
			cout<<ans+dis[x][y]<<endl;
			continue;
		}
		vvis[x]=1;
		dis[x][x]=0;
		while(!pq.empty())pq.pop();
		pq.push((nod){x,dis[x][x]});
		while(!pq.empty()){
			int v=pq.top().v;
			pq.pop();
			if(vis[x][v])continue;
			vis[x][v]=true;
			int siz=G[v].size();
			for(int i=0;i<siz;i++){
				int to=G[v][i].v;
				if(dis[x][to]>=dis[x][v]+G[v][i].w){
					dis[x][to]=dis[x][v]+G[v][i].w;
					if(!vis[x][to])pq.push((nod){to,dis[x][to]});
				}
			}
		}
		cout<<ans+dis[x][y]<<endl;
	}
	return 0;
}
