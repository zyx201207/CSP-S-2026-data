#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,N,M,D,Q;
ll w[500010];
typedef pair<ll,int> P;
vector<P> G[510];
vector<P> edge[500010];
ll dis[510][510];
bool vis[500010];
void dij(int x){
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,x));
	memset(vis,false,sizeof(vis));
	dis[x][x]=0; 
	while(que.size()){
		int t=que.top().second;
		que.pop();
		if(vis[t]){
			continue;
		}
		vis[t]=1;
		for(int i=0;i<G[t].size();i++){
			int v=G[t][i].second,w=G[t][i].first;
			if(dis[x][v]>dis[x][t]+w){
				dis[x][v]=dis[x][t]+w;
				que.push(P(dis[x][v],v));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&N,&M,&D,&Q);
	for(int i=1;i<=M;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=N;i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;j++){
			int x;
			int y; 
			scanf("%d%d",&x,&y);
			edge[x].push_back(P(i,y));
		}
    }
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=N;j++){
    		dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=0;j<edge[i].size();j++){
			for(int k=0;k<edge[i].size();k++){
				if(k!=j){
					G[edge[i][k].first].push_back(P((ll)edge[i][j].second+edge[i][k].second,edge[i][j].first));
					G[edge[i][j].first].push_back(P((ll)edge[i][j].second+edge[i][k].second,edge[i][k].first));
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		dij(i);
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(int j=0;j<edge[x].size();j++){
			for(int k=0;k<edge[y].size();k++){
				ans=min(dis[edge[y][k].first][edge[x][j].first]+w[x]+edge[x][j].second+edge[y][k].second+w[y],ans);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

