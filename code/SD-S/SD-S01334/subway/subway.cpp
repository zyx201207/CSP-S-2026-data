#include <iostream>
#include <queue>
#include <vector>
#define PII pair<int,int>
using namespace std;
int c,n,m,d,T;
int w[500010];
long long dis[510][510];
vector<PII> disf[510];
PII to[500010][22];
int cnt[500010];

long long bw[510][510];

priority_queue<PII,vector<PII>,greater<PII> > q;
bool st[510];
void dij(int sta){
	for(int i=0;i<=505;i++) st[i]=0;
	q.push({0,sta});
	dis[sta][sta]=0;
	st[sta]=1;
	while(q.size()){
		int u=q.top().second;q.pop();
		st[u]=1;
//		cerr<<u<<":\n";
		for(int v=1;v<=n;v++){
			if(bw[u][v]==1e18+10) continue;
			if(st[v]) continue;
			dis[sta][v]=min(dis[sta][u]+bw[u][v],dis[sta][v]);
//			cerr<<"dis of"<<v<<" change to"<<dis[sta][v]<<"\n";
			q.push({dis[sta][v],v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
	for(int i=0;i<=505;i++){
		for(int j=0;j<=505;j++){
			dis[i][j]=1e18+10;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			disf[i].push_back({a,t});
			cnt[a]++;
			to[a][cnt[a]]={i,t};
		}
	}
	for(int i=0;i<=505;i++){
		for(int j=0;j<=505;j++){
			bw[i][j]=1e18+10;
		}
	}
	for(int u=1;u<=n;u++){
		for(PII i:disf[u]){
			for(int j=1;j<=cnt[i.first];j++){
				int v=to[i.first][j].first;
				long long W=i.second+to[i.first][j].second;
				bw[u][v]=min(bw[u][v],W);
				bw[v][u]=min(bw[v][u],W);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e18+10;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,dis[to[x][i].first][to[y][j].first]+to[x][i].second+to[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
