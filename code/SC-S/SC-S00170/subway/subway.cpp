#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509,M=5e5+9;
int c,n,m,d,q;
int w0[M];
struct node{
	int sid,t;
};
vector<node>a[M];
int w1[N][N];
int dist[N][N];bool vis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w0[i]);
	memset(dist,0x3f,sizeof(dist));
	memset(w1,0x3f,sizeof(w1));
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,t;
			scanf("%lld%lld",&x,&t);
			for(node y:a[x])
				w1[y.sid][i]=w1[i][y.sid]=min(w1[y.sid][i],y.t+t);
			a[x].push_back({i,t});
		}
	}
	for(int s=1;s<=n;s++){
		dist[s][s]=0;
		while(1){
			int u=0;
			for(int v=1;v<=n;v++)
				if(!vis[s][v]&&dist[s][v]<dist[s][u])
					u=v;
			if(u==0)break;
			vis[s][u]=1;
			for(int v=1;v<=n;v++)
				if(dist[s][v]>dist[s][u]+w1[u][v])
					dist[s][v]=dist[s][u]+w1[u][v];
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(node u:a[x])
			for(node v:a[y])
				ans=min(ans,w0[x]+w0[y]+u.t+v.t+dist[u.sid][v.sid]);
		printf("%lld\n",ans);
	}
}