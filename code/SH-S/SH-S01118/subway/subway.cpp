#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k[501],w[500001],tot[500001],t[501][501],a[501][501],dis[501][501],cost[501][501];
pair<int,int> coss[500001][21];
bool vis[501],bri[501][501];
vector<int> g[501];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
void dijkstra(int st){
	while(!que.empty())que.pop();
	que.push({0,st});
	while(!que.empty()){
		auto now=que.top();
		que.pop();
		if(vis[now.second])continue;
		vis[now.second]=1;
		for(auto nxt:g[now.second]){
			if(vis[nxt])continue;
			if(dis[st][now.second]+cost[now.second][nxt]<dis[st][nxt]){
				dis[st][nxt]=dis[st][now.second]+cost[now.second][nxt];
				que.push({dis[st][nxt],nxt});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			//s[a[i][j]][i]={i,t[i][j]};
			coss[a[i][j]][++tot[a[i][j]]]={i,t[i][j]};
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=1;u<=tot[i];u++){
			for(int v=u+1;v<=tot[i];v++){
				int gu=coss[i][u].first,gv=coss[i][v].first,guc=coss[i][u].second,gvc=coss[i][v].second;
				if(!bri[gu][gv]){
					g[gu].push_back(gv);
					g[gv].push_back(gu);
					cost[gu][gv]=guc+gvc;
					cost[gv][gu]=guc+gvc;
				}
				else {
					cost[gu][gv]=min(cost[gu][gv],guc+gvc);
					cost[gv][gu]=min(cost[gv][gu],guc+gvc);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j]=0;
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
		dijkstra(i);
	}
	for(int i=1,u,v,ans;i<=q;i++){
		cin>>u>>v;
		ans=1e18;
		for(int st1=1;st1<=tot[u];st1++){
			for(int st2=1;st2<=tot[v];st2++){
				ans=min(ans,dis[coss[u][st1].first][coss[v][st2].first]+coss[u][st1].second+coss[v][st2].second);
				//cout<<"cost:"<<coss[u][st1].first<<" "<<coss[v][st2].first<<" "<<dis[coss[u][st1].first][coss[v][st2].first]<<"\n";
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
