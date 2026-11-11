#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T,w[500010],k[510],vis[500010],x,y,f[500010],ans[100010];
struct node{
	int x,dis;
};
struct no{
	int x,dis;
	bool operator <(no a)const{
		return dis>a.dis;
	}
};
vector<node> g[500010],a[510];
void dij(int x){
	queue<no> q;
	for(int i=1;i<=m;i++)f[i]=2e18;
	f[x]=0;
	vis[x]=1;
	q.push({x,0});
	while(!q.empty()){
		int fx=q.front().x,fb=q.front().dis;q.pop();
		vis[fx]=0;
		for(int i=0;i<g[fx].size();i++){
			int xl=g[fx][i].x;
			for(int j=1;j<=k[xl];j++){
				int sx=a[xl][j].x,sb=fb+g[fx][i].dis+a[xl][j].dis;
				if(f[sx]<=sb)continue;
				f[sx]=sb;
				if(vis[sx]==0)vis[sx]=1,q.push({sx,sb});
			}
		}
	}
}
struct noo{
	int x,y,id;
}q[100010];
bool op(noo q,noo h){
	return q.x<h.x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back({0,0});
		for(int j=1;j<=k[i];j++)
			cin>>x>>y,a[i].push_back({x,y}),g[x].push_back({i,y});
	}
	for(int i=1;i<=T;i++)
		cin>>q[i].x>>q[i].y,q[i].id=i;
	sort(q+1,q+1+T,op);
	for(int i=1;i<=T;i++){
		if(q[i].x!=q[i-1].x)dij(q[i].x);
		ans[q[i].id]=w[q[i].x]+w[q[i].y]+f[q[i].y];
	}
	for(int i=1;i<=T;i++)cout<<ans[i]<<'\n';
	return 0;
}
