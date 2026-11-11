#include<bits/stdc++.h>
#define MAXN 600010
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
int c,n,m,q;
ll w[MAXN],ans[MAXN],dis[MAXN];
vector<pair<int,ll> > G[MAXN];
vector<pair<int,int> > ask[MAXN];
bool vis[MAXN];
inline void Dijkstra(int from){
	fill(vis+1,vis+1+m+n,0);
	fill(dis+1,dis+1+m+n,1e16);
	dis[from]=0;
	priority_queue<pli,vector<pli>,greater<pli> > q;
	q.push(make_pair(0,from));
	while(!q.empty()){
		int from=q.top().second;
//		cout<<from<<endl;
		q.pop();
		if(vis[from]){
			continue;
		}
		vis[from]=true;
		for(int i=0;i<G[from].size();++i){
			int to=G[from][i].first;
			if(dis[to]>dis[from]+G[from][i].second){
				dis[to]=dis[from]+G[from][i].second;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %*d %d",&c,&n,&m,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		while(k--){
			int link;
			ll tim;
			scanf("%d %lld",&link,&tim);
			G[m+i].push_back(make_pair(link,tim));
			G[link].push_back(make_pair(m+i,tim));
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		ask[x].push_back(make_pair(y,i));
	} 
	for(int i=1;i<=m;++i){
		Dijkstra(i);
		for(int j=0;j<ask[i].size();++j){
			ans[ask[i][j].second]=dis[ask[i][j].first]+w[i]+w[ask[i][j].first];
		}
	}
	for(int i=1;i<=q;++i){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
