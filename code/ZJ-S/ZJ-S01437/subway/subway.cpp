#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define int long long
#define Dis dis[s]
//rp++;
const int maxn=1<<19;
const int inf=0x9999FFll*20160812ll;
int n,m,d,q;
//n线路数 m站数
int en[maxn];
struct edge {
	int v,w;
	bool operator<(const edge& e2)const {
		return w<e2.w;
	}
};
vector<edge>ex[maxn];
int g[512][512];
int dis[512][512];
void dijkstra(int s) {
	for(int i=1; i<=n; i++)Dis[i]=inf;
	Dis[s]=0;
	priority_queue<edge>q;
	q.push({s,0});
	while(!q.empty()) {
		int u=q.top().v;
		int udis=q.top().w;
		q.pop();
		if(udis>Dis[u])continue;
		for(int v=1; v<=n; v++) {
			if(u==v)continue;
			if(udis+g[u][v]<Dis[v]) {
				Dis[v]=udis+g[u][v];
				q.push({v,Dis[v]});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0; i<512; i++)for(int j=0; j<512; j++)g[i][j]=(i==j?0:inf);
	cin>>n>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>en[i];//地面到站厅时间
	for(int i=1; i<=n; i++) {//各条地铁线路
		int k;
		cin>>k;
		while(k--) {
			int v,w;
			cin>>v>>w;//经停站
			ex[v].push_back({i,w});//v站厅到i站台时间
		}
	}
	for(int i=1; i<=m; i++)//i站点
		for(edge it1:ex[i])//it1.v号线
			for(edge it2:ex[i]) {//it2.v号线
				if(it1.v!=it2.v&&g[it1.v][it2.v]==0) {
					g[it1.v][it2.v]=it1.w+it2.w;
					g[it2.v][it1.v]=it1.w+it2.w;
				} else {
					g[it1.v][it2.v]=min(g[it1.v][it2.v],it1.w+it2.w);
					g[it2.v][it1.v]=min(g[it2.v][it1.v],it1.w+it2.w);
				}
			}
	//��￡你要不赔我一双眼睛吧，读题已经给我看得晕乎乎的，结果还要去重，那我只能标一堆注释了
	for(int i=1; i<=n; i++)dijkstra(i);
	while(q--) {
		int s,t,res=inf;
		cin>>s>>t;
		for(auto it1:ex[s])for(auto it2:ex[t])
				res=min(res,it1.w+it2.w+dis[it1.v][it2.v]);
		cout<<en[s]+en[t]+res<<'\n';
	}
	return 0;
}
/*
杭州东站和东站北广场出站换乘
考点门口19号线噪音太大拆掉重建
3号线支线是啥阴
牢杭觉得自己老有操作了
从云飞路直接走到丽江路只需要5分钟
翠柏里不能站内换乘
泽民换乘走廊长达800米
牢甬觉得自己老有操作了
牢越你也逃不掉，说说把于越路和高铁当渐近线是怎么回事
*/
