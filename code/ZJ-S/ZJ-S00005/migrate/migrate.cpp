#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int dist[N],cnt[N];
long long x[N];
vector<int>g[N];
bool vis[N];
void dij(int x) {
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dist[x]=0;
	cnt[x]=1;
	queue<int>q;
	q.push(x);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]) {
			if(dist[v]>dist[u]+1||dist[v]==dist[u]+1){
				cnt[v]+=cnt[u];
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	scanf("%d%d",&c,&T);
	while(T--) {
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(x[j]>d+x[i])break;
				g[i].push_back(j);
			}
		}
		long long res=0;
		dij(1);
		for(int i=1; i<=n; i++) {
			dij(i);
			for(int j=i+1; j<=n; j++) {
				if(cnt[j]==2) {
					res++;
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
