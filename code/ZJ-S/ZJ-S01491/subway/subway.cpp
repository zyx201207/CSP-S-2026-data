#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,int>
using namespace std;
const int M=500500;
const ll INF=1e15;
int c,n,m,d,q,x,y,k,a;
ll t;
vector<pair<int,ll> > lo[M];
ll w[M];
ll g[505][505];
ll dis[505][505];
queue<int> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=dis[i][j]=INF;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&a,&t);
			for(int jj=0;jj<(int)lo[a].size();jj++){
				if(lo[a][jj].first==i) continue;
				g[i][lo[a][jj].first]=g[lo[a][jj].first][i]=min(g[i][lo[a][jj].first],lo[a][jj].second+t);
			}
			lo[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		while(!pq.empty()) pq.pop();
		pq.push(i);
		while(!pq.empty()){
			int xx=pq.front();
			pq.pop();
			for(int j=1;j<=n;j++){
				if(xx==j) continue;
				if(dis[i][xx]+g[xx][j]<dis[i][j]){
					dis[i][j]=dis[i][xx]+g[xx][j];
					pq.push(j);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ll ans=INF;
		for(int j=0;j<(int)lo[x].size();j++){
			for(int jj=0;jj<(int)lo[y].size();jj++){
				ans=min(ans,w[x]+w[y]+lo[x][j].second+lo[y][jj].second+dis[lo[x][j].first][lo[y][jj].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}