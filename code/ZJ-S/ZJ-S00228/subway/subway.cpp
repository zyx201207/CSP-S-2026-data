#include<bits/stdc++.h>
using namespace std;
const int M=1105;
const long long inf=1e18;
int w[M];
int c,n,m,d,q,ki,value1,value2;
struct point{
	int ni;
	long long t;
};
vector<point> a[505];
struct edge{
	int to;
	long long info;
	bool operator<(const edge &other)const{
		return to<other.to;
	}
};
struct node{
	long long di;
	int ni;
	bool operator>(const node &other)const{
		return di<other.di;
	}
};
bool vis[M];
long long dis[M];
vector<edge> e[M];
long long ans[M][M];
void dist(int start){
	memset(vis,false,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	priority_queue<node,vector<node>,greater<node> > p;
	dis[start]=0;
	p.push({0,start});
	while(!p.empty()){
		node u=p.top();
		p.pop();
		long long di=u.di;
		int x=u.ni;
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=0;i<e[x].size();i++){
			edge v=e[x][i];
			if(dis[v.to]!=inf&&dis[v.to]+v.info<dis[x]){
				dis[x]=dis[v.to]+v.info;
			}
		}
		for(int i=0;i<e[x].size();i++){
			edge v=e[x][i];
			if(dis[v.to]==inf){
				dis[v.to]=dis[x]+v.info;
				p.push({dis[v.to],v.to});
			}
		}
	}
	for(int i=1;i<=m;i++) ans[start][i]=dis[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c>11) return 0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>value1>>value2;
			a[i].push_back({value1,value2});
		}
		for(int k=0;k<=a[i].size();k++){
			point c=a[i][k];
			for(int k1=0;k1<=a[i].size();k1++){
				point b=a[i][k1];
				if(c.ni==b.ni) continue;
				edge ei={b.ni,b.t+c.t};
				int x=lower_bound(e[c.ni].begin(),e[c.ni].end(),ei)-e[c.ni].begin();
				if(x!=e[c.ni].size()&&e[c.ni][x].to==b.ni) e[c.ni][x].info=min(e[c.ni][x].info,ei.info);
				else e[i].insert(x+e[c.ni].begin(),ei);
			}
		}
	}
	for(int i=1;i<=m;i++) dist(i);
	int u,v;
	while(q--){
		cin>>u>>v;
		cout<<ans[u][v]<<"\n";
	} 
	return 0;
}
 
