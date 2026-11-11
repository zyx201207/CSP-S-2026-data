#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const int M=5e5+10,N=5e2+10;
ll c,n,m,d,q,w[M],a,t,U,V,W,kk,dis[N][N],fro,to,ans,trans;
struct Station{
	ll cnt,Line[20][2];
}sta[M];
vector<pair<ll,ll> >g[N];
bool vis[N];
void dikjstra(int S){
	priority_queue<PII,vector<PII>,greater<PII> >q;
	memset(vis,0,sizeof(vis));
	dis[S][S]=0;
	q.push({0,S});
	while(!q.empty()){
		int D=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.first,di=x.second;
			if(dis[S][v]>D+di){
				dis[S][v]=D+di;
				q.push({dis[S][v],v});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&kk);
		while(kk--){
			scanf("%lld%lld",&a,&t);
			sta[a].Line[++sta[a].cnt][0]=i;
			sta[a].Line[sta[a].cnt][1]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<sta[i].cnt;j++){
			for(int k=j+1;k<=sta[i].cnt;k++){
				U=sta[i].Line[j][0],V=sta[i].Line[k][0],W=sta[i].Line[j][1]+sta[i].Line[k][1];
				g[U].push_back({V,W});
				g[V].push_back({U,W});
			}
		}
	}
	for(int i=1;i<=n;i++)dikjstra(i);
	while(q--){
		trans=INT_MAX;
		scanf("%lld%lld",&fro,&to);
		for(int i=1;i<=sta[fro].cnt;i++){
			for(int j=1;j<=sta[to].cnt;j++){
				trans=min(trans,sta[fro].Line[i][1]+sta[to].Line[j][1]+dis[sta[fro].Line[i][0]][sta[to].Line[j][0]]);
			}
		}
		printf("%lld\n",trans+w[fro]+w[to]);
	}
	return 0;
}
