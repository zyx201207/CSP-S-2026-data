#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q,w[500010],dis[510],bg,ed,in[510],fuck,ans[510][510];
vector<pair<int,int> >g[510],edge[500010];
priority_queue<pair<int,int> >qq;
void build(int u){
	for(int i=0;i<edge[u].size();i++){
		for(int j=0;j<edge[u].size();j++){
			int v1=edge[u][i].first,v2=edge[u][j].first;
			if(ans[v1][v2]){
				continue;
			}
			ans[v1][v2]=1;
			ans[v2][v1]=1;
			fuck++;
			g[v1].push_back({v2,edge[u][i].second+edge[u][j].second});
			g[v2].push_back({v1,edge[u][i].second+edge[u][j].second});
		}
	}
}
int solve(){
	int res=1e18;
	for(int i=0;i<edge[bg].size();i++){
		for(int j=0;j<edge[ed].size();j++){
			int u=edge[bg][i].first,v=edge[ed][j].first;
			res=min(w[bg]+w[ed]+ans[u][v]+edge[bg][i].second+edge[ed][j].second,res);
		}
	}
	return res;
}
void dij(int beg){
	memset(dis,0x3f,sizeof(dis));
	dis[beg]=0;
	qq.push({0,beg});
	while(!qq.empty()){
		int u=qq.top().second;
		in[u]=0;
		qq.pop();
		if(u==n+1){
			continue;
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!in[v]){
					qq.push({dis[v]*-1,v});
					in[v]=1;
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			edge[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		build(i);
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++){
			ans[i][j]=dis[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>bg>>ed;
		cout<<solve()<<"\n";
	}
	return 0;
}
