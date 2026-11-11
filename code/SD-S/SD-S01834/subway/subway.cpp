#include<bits/stdc++.h>
#define deb(a) cerr<<#a<<"="<<(a)<<endl 
using namespace std;
#define i64 long long
#define int i64
const int maxn=1e6+10;

int _c,n,m,D,Q;

//int tot;

int w[maxn];

int G[510][510];
#define pii pair<int,int>
basic_string<pii> hu[maxn];

//basic_string<pii >G[maxn];

//int dis[maxn];bool vis[maxn];
//priority_queue<pii,vector<pii>,greater<pii> >pq;
//
//int dij(int S,int T){
//	memset(vis+1,0,tot*sizeof vis[0]);
//	memset(dis+1,0x3f,tot*sizeof dis[0]);
//	
//	pq.push({dis[S]=0,S});
//	while(!pq.empty()){
//		auto tp=pq.top();
//		int u=tp.second;
//		pq.pop();
//		if(vis[u])continue;
//		vis[u]=1;
////		if(u==T){
////			return dis[u];
////			deb(dis[u]);
////		}//break;
//		for(auto E:G[u]){
//			int v=E.first,w=E.second;
//			if(dis[v]>dis[u]+w){
////				assert(!vis[v]);
//				pq.push({dis[v]=dis[u]+w,v});
//			}
//		}
//	}
////	deb(dis[T]);
//	return dis[T];
//}

void cmin(int&a,int b){a=min(a,b);}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_c>>n>>m>>D>>Q;
	
	for(int i=1;i<=m;++i)cin>>w[i];

	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1,a,t;j<=k;++j){
			cin>>a>>t;
			hu[a].push_back(pii{i,t});
		}
	}
	
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		G[i][j]=1e18;
	for(int i=1;i<=n;++i)G[i][i]=0;
 
 	for(int i=1;i<=m;++i){
 		for(auto e1:hu[i])for(auto e2:hu[i]){
 			int a=e1.first,b=e2.first;
 			cmin(G[a][b],e1.second+e2.second);
		 }
	 }
	 for(int i=1;i<=n;++i)
	 for(int j=1;j<=n;++j)
	 for(int k=1;k<=n;++k)
	 cmin(G[j][k],G[j][i]+G[i][k]);
	 
	  
	
//	tot=m;
//	for(int i=1;i<=n;++i){
//		int k;cin>>k;
//		int pr=0;
//		for(int j=1;j<=k;++j){
//			int a,t;cin>>a>>t;
//			int cr=++tot;
//			G[cr]+=pii{a,t};
//			G[a]+=pii{cr,t};
//			if(pr){
//				G[pr]+=pii{cr,0};
//				G[cr]+=pii{pr,0};
//			}
//			pr=cr;
//		}
//	}
//	
	while(Q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for(auto e1:hu[x])for(auto e2:hu[y]){
			ans=min(ans,G[e1.first][e2.first]+e1.second+e2.second);
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
}
