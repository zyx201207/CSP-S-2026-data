#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
ll wa[M],disl[N][N];
struct node{
	int to,next;
	ll w;
}e[M*2*2];
int cnt,head[M+N],k[N];
void addedge(int u,int v,ll w){
	cnt++;
	e[cnt].to=v; e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
vector<pii> tol[M];
bool vis[M+N];

ll dis[M+N];
void dijkstra(int rt){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[rt]=0;
	q.push({0,rt+m});
	while(!q.empty()){
		int u=q.top().second;
		ll di=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u>m){
			disl[rt][u-m]=min(disl[rt][u-m],di);
			disl[u-m][rt]=min(disl[u-m][rt],di);
			//disl[rt][u-m]=disl[u-m][rt]=di;
		}
		for(int i=head[u];i;i=e[i].next){
			int to=e[i].to;
			ll w=e[i].w;
			if(dis[to]>di+w){
				dis[to]=di+w;
				q.push({dis[to],to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> wa[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int a; ll t;
			cin >> a >> t;
			addedge(a,m+i,t);
			addedge(m+i,a,t);
			tol[a].push_back({t,i});
		}
	}
	memset(disl,0x3f,sizeof(disl));
	for(int i=1;i<=n;i++){
		dijkstra(i);
		disl[i][i]=0;
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		ll ans=1e18;
		for(auto iti=tol[x].begin();iti!=tol[x].end();iti++){
			for(auto itj=tol[y].begin();itj!=tol[y].end();itj++){
				int xx=(*iti).second;
				int yy=(*itj).second;
				ll xd=(*iti).first;
				ll yd=(*itj).first;
				ans=min(ans,disl[xx][yy]+xd+yd);
				//cout << xx << ' ' << yy << ' ' << disl[xx][yy] << '\n';
			}	
		}
		cout << ans+wa[x]+wa[y] << '\n';
	}
	return 0;
}
