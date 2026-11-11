#include<bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
using namespace std;
int c,n,m,d,q,w[500005];
ll dis[505][505];
vector<pii>G[500505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		dis[i][i]=0;
		for(int j=1,u,w;j<=k;j++){
			scanf("%d %d",&u,&w);
			G[m+i].push_back(mp(u,w));
			G[u].push_back(mp(m+i,w));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=j+1;k<G[i].size();k++){
				int u=G[i][j].first-m,wu=G[i][j].second,v=G[i][k].first-m,wv=G[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],1ll*wu+wv);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=LLONG_MAX;
		for(auto it:G[u]){
			for(auto itt:G[v]){
				ll res = it.second+dis[it.first-m][itt.first-m]+itt.second;
				ans=min(ans,res);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]); 
	}
	return 0;
}/* 
15:57 为什么没记快读qwq 
*/
