#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,w[maxn],d,c,q,dis[1005][1005];
vector<pair<int,int> >V[505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
bool vis[maxn];
struct ST{
	int x,len;
};
vector<ST>G[1005];
void Dij(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[s][i]=1e18;
	dis[s][s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].x;
			if(dis[s][v]>dis[s][u]+G[u][i].len){
				dis[s][v]=dis[s][u]+G[u][i].len;
				pq.push({dis[s][v],v});
			}
		}
	}
}
bool mp[505][505];
vector<int>id[maxn]; 
queue<pair<int,int> >Q;
int col[maxn],cost[maxn][2];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			V[i].push_back({v,t});
		}
	}
	if(c<=6){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
		for(int i=1;i<=m;i++){
			for(int j=0;j<V[i].size();j++){
				for(int k=j+1;k<V[i].size();k++){
					dis[V[i][j].first][V[i][k].first]=min(dis[V[i][j].first][V[i][k].first],V[i][j].second+V[i][k].second);
					dis[V[i][k].first][V[i][j].first]=min(dis[V[i][k].first][V[i][j].first],V[i][k].second+V[i][j].second);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(k==i||i==j||j==k)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
	}else if(c<=11){
		for(int i=1;i<=m;i++){
			if(V[i].size()==1)continue;
			G[V[i][0].first].push_back({V[i][1].first,V[i][0].second+V[i][1].second});
			G[V[i][1].first].push_back({V[i][0].first,V[i][0].second+V[i][1].second});
		}
		for(int i=1;i<=n;i++)Dij(i);
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<'\n';
		}
	}else if(c<=19){
		//do some thing
		for(int i=1;i<=m;i++)for(pair<int,int> j:V[i])id[j.first].push_back(i);
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=n;i++)vis[i]=0;
			while(!Q.empty())Q.pop();
			vis[x]=1;
			Q.push({x,0});
			while(!Q.empty()){
				int u=Q.front().first;
				int t=Q.front().second;
				Q.pop();
				if(u==y){
					cout<<Q.front().second+w[x]+w[y]<<'\n';
					break;
				}
				for(int i:id[u]){
					for(pair<int,int> j:V[i]){
						if(!vis[j.first]){
							Q.push({j.first,t+j.second*2});
							vis[j.first]=1;
						}
					}
				}
			}
		}
	}
	return 0;
}
/*
15:06才读懂题！！！
我咋感觉这是个超级简单题呢，后两题感觉不可做拼包大作战是吧 
完啦看错题啦！！！
一条线路只经过一次，每次一定只到中转点，所以一条最短路最多500个点
中转点最多500个吗？不对有可能线路会重复多个点
重叠多个可以缩吗？好像不行得利用好每个点最多覆盖20次
不对啊我好像可以吧线路看做点跑Floyed，不行
我肯定得把这题过了，我钦定这题是超级简单题 
16:40
做不出来T2我不甘心，做了出来T2我会爆炸 
不管咋都是遗憾了 
初一。就这样吧（合眼） 
不管正解是什么都不要可惜！ 
*/
