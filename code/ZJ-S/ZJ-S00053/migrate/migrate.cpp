#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d;
vector<int>g[2000005];
pair<int,long long>dis[5005][5005];
priority_queue<pair<pair<int,long long>,int>,vector<pair<pair<int,long long>,int> >,greater<pair<pair<int,long long>,int> > >pq;
static inline void dijkstra(int st){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;i++)dis[st][i]={1e9,0};
	dis[st][st]={0,1};
	pq.push({dis[st][st],st});
	while(!pq.empty()){
		int u=pq.top().second,d=pq.top().first.first;
		long long cnt=pq.top().first.second;
		pq.pop();
		if(d!=dis[st][u].first||cnt!=dis[st][u].second)continue;
		for(auto v:g[u]){
			if(dis[st][u].first+1<dis[st][v].first){
				dis[st][v].first=dis[st][u].first+1;
				dis[st][v].second=dis[st][u].second;
				pq.push({dis[st][v],v});
			}
			else if(dis[st][u].first+1==dis[st][v].first){
				dis[st][v].second+=dis[st][u].second;
				pq.push({dis[st][v],v});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long D=x[j]-x[i];
				if(D<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)dijkstra(i);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j].first!=1e9&&dis[i][j].second==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
