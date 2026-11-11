#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	int v;
	ll w;
};
const int N=5e5+10;
vector<edge>gx[505];
vector<edge>g[N];
ll w[N],dis[505][505];
int vis[505];
int c,n,m,d,q;
void dij(int s){
	priority_queue< pair<ll,int> >q;
	for(int i=1;i<=n;i++)vis[i]=0; 
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:gx[u]){
			if(vis[v.v])continue;
			if(dis[s][u]+v.w<dis[s][v.v]){
				dis[s][v.v]=dis[s][u]+v.w;
				q.push({-dis[s][v.v],v.v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int u,k,x,y;
	ll ww;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&u,&ww);
			for(auto v:g[u]){
				gx[i].push_back(edge{v.v,v.w+ww});
				gx[v.v].push_back(edge{i,v.w+ww});
			}
			g[u].push_back(edge{i,ww});
		}
	}
//	for(int i=1;i<=m;i++){
//		for(auto v:g[i]){
//			cout<<v.v<<' '<<v.w<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(auto v:gx[i]){
//			cout<<v.v<<' '<<v.w<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0x1f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(q--){
		ll ans=0x1f3f3f3f3f3f3f3f;
		scanf("%d%d",&x,&y);
		for(auto st1:g[x]){
			for(auto st2:g[y]){
				int xx=st1.v,yy=st2.v;
				ans=min(ans,dis[xx][yy]+st1.w+st2.w);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}