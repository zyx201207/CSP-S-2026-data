#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1005,N=5e5+5;
struct node{
	int x;
	int lst;
	int step;
	bool operator<(const node&other) const{
		return step>other.step;
	}
};
int c,n,m,d,q;
int w[maxn];
vector<int>line[N];
bool vis[maxn][maxn];
vector<pair<int,int> >G[maxn];//点->路线站台门
int dis[maxn][maxn];
int jiyi[maxn][maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>q;//测试点编号 路线的数量 点的数量 每个地铁站最多被几条线路经过 查询次数 
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;//第i条路线经过的站点数量
		int lst=0;
		while(k--){
			int id;
			cin>>id;
			int w;
			cin>>w; 
			line[i].push_back(id);
			G[id].push_back({i,w});
		} 
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		if(jiyi[st][ed]){
			cout<<jiyi[st][ed]<<"\n";
			continue;
		}
		if(st==ed){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=1e18;
				vis[i][j]=false;
			} 
		}
		priority_queue<node>q;
	    for(int i=0;i<G[st].size();i++){
	    	int v=G[st][i].first,ww=G[st][i].second;
	    	dis[st][v]=ww;
	    	q.push({st,v,dis[i][v]});
		}
		while(!q.empty()){
			node t=q.top();
			q.pop();
			int u=t.x;
			if(vis[u][t.lst]) continue;
			vis[u][t.lst]=true;
			//cout<<u<<" "<<t.lst<<" "<<dis[u][t.lst]<<endl;
			for(int i=0;i<line[t.lst].size();i++){
				int v=line[t.lst][i];
				if(v==u) continue;
				//cout<<v<<" "<<t.lst<<" "<<dis[v][t.lst]<<" "<<dis[u][t.lst]<<endl;
				if(dis[v][t.lst]>dis[u][t.lst]){
					dis[v][t.lst]=dis[u][t.lst];
					q.push({v,t.lst,dis[v][t.lst]});
				}
			}
			int id=-1;
			for(int i=0;i<G[u].size();i++){
				if(t.lst==G[u][i].first){
					id=i;
					break;
				}
			}
			if(G[u].size()<2) continue; 
			//cout<<id<<endl;
			for(int j=0;j<G[u].size();j++){
				if(dis[u][G[u][j].first]>dis[u][t.lst]+G[u][id].second+G[u][j].second){
					dis[u][G[u][j].first]=dis[u][t.lst]+G[u][id].second+G[u][j].second;
					q.push({u,G[u][j].first,dis[u][j]});
				}
			}
		}
		int mini=1e18;
		for(int i=1;i<=m;i++){
			int id=-1;
			for(int j=0;j<G[ed].size();j++){
				if(G[ed][j].first==i){
					id=j;
					break;
				}
			}
			if(id==-1) continue;
			//cout<<dis[ed][i]<<" "<<G[ed][id].second<<endl;
			mini=min(mini,dis[ed][i]+G[ed][id].second);
		}
		jiyi[st][ed]=mini+w[st]+w[ed];
		cout<<mini+w[st]+w[ed]<<"\n";
	}
	return 0;
}
