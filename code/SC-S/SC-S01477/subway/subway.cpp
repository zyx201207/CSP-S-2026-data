#include<bits/stdc++.h>
#define int long long
#define ri register int
#define ls(x) x<<1
#define rs(x) x<<1|1
#define PINF 1e18
#define NINF 1e18
#define inf 500514
#define mf 5011
#define sf 511
#define mp make_pair
#define pii pair<int,int>
using namespace std;
//性质1:从地铁线的角度出发去建图，答案等于 min{离开和进入的贡献+转站的贡献}
//性质2:转站的贡献依靠dijkstra跑出来（一个图最多500个地铁线，250000条边）
int c,n,m,d,q,num[inf];
int dis[sf][sf];
map<int,int> cst[sf];
//cst[i][j]:第i个站点中j号地铁站的出入站时间
vector<pii> rcd[inf];
//rcd[i]={(a,b)}:第i个节点的“（经过的地铁线，代价）”的集合
vector<pii> orggraph[sf];
bool vis[sf];
void dijkstra(int srt){
	memset(vis,false,sizeof(vis));
	dis[srt][srt]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q; q.push(mp(0ll,srt));
	while(!q.empty()){
		int u=q.top().second; q.pop();
		if(vis[u]) continue;
		else vis[u]=true;
		for(ri i=0;i<orggraph[u].size();i++){
			int v=orggraph[u][i].first,w=orggraph[u][i].second;
			if(dis[srt][u]+w<dis[srt][v]){
				dis[srt][v]=dis[srt][u]+1ll*w;
				q.push(mp(dis[srt][v],v));
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ri i=1;i<=m;i++) cin >> num[i];
	
	//处理集合
	for(ri i=1;i<=n;i++){
		int a; cin >> a;
		for(ri j=1;j<=a;j++){
			int b,c; cin >> b >> c;
			cst[i][b]=c;
			rcd[b].push_back(mp(i,c));
		}
	}
	//处理地铁线之间的边,吃满跑 2e8
	for(ri i=1;i<=n;i++) for(ri j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=PINF+2ll;
	for(ri i=1;i<=m;i++){
		if(rcd[i].size()<=1) continue;
		for(ri j=0;j<rcd[i].size();j++) for(ri k=j+1;k<rcd[i].size();k++){
			int u=rcd[i][j].first,v=rcd[i][k].first;
			dis[v][u]=dis[u][v]=min(dis[u][v],1ll*rcd[i][j].second+1ll*rcd[i][k].second);
		}
	}
	//开始转图
	for(ri i=1;i<=n;i++) for(ri j=i+1;j<=n;j++){
		if(dis[i][j]>PINF) continue;
		orggraph[i].push_back(mp(j,dis[i][j]));
		orggraph[j].push_back(mp(i,dis[j][i]));
	}
	//开始跑最小代价
	for(ri i=1;i<=n;i++) for(ri j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=PINF+2ll;
	for(ri i=1;i<=n;i++) dijkstra(i);
	//开始统计答案,吃满跑 4e7
	for(ri i=1;i<=q;i++){
		int u,v; int ans=1e18; cin >> u >> v;
		for(ri j=0;j<rcd[u].size();j++) for(ri k=0;k<rcd[v].size();k++){
			int x=rcd[u][j].first,y=rcd[v][k].first;
			ans=min(ans,num[u]+num[v]+dis[x][y]+cst[x][u]+cst[y][v]);
		}
		cout << ans << endl;
	}
	return 0;
}