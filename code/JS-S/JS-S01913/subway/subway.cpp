#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e5+5;
int c,n,m,d,q,w[N],head[N+505],cnt,dist[505][N+505];
bool vis[N+505];
struct awa{
	int to,w,next;
}e[2*N];
void add(int u,int v,int w){
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
void dj(int s,int t){
	memset(vis,0,sizeof vis);
	priority_queue<PII,vector<PII>,greater<PII>> q;
	dist[t][s]=0;
	q.push({dist[t][s],s});
	while(!q.empty()){
		int ns=q.top().second;
		q.pop();
		if(vis[ns]){
			continue;
		}
		vis[ns]=1;
		for(int i=head[ns];i;i=e[i].next){
			int to=e[i].to,w=e[i].w;
			if(dist[t][ns]+w<dist[t][to]){
				dist[t][to]=dist[t][ns]+w;
				q.push({dist[t][to],to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int v,t;
			scanf("%lld%lld",&v,&t);
			add(m+i,v,t);
			add(v,m+i,t);
		}
	}
	for(int i=m+1;i<=m+n;i++){
		dj(i,i-m);
	}
	while(q--){
		int u,v;
		scanf("%lld%lld",&u,&v);
		int minn=1e18;
		for(int i=m+1;i<=m+n;i++){
			minn=min(minn,dist[i-m][u]+dist[i-m][v]);
		}
		printf("%lld\n",minn+w[u]+w[v]);
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
