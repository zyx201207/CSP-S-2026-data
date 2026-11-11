#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=5e5+10;
const ll inf=1e18;
struct node{
	int id;
	ll t;
};
vector <node> e[M];
ll dis[N][N],w[M];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			node tmp;
			tmp.id=i,tmp.t=t;
			e[a].push_back(tmp);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto u:e[i]){
			for(auto v:e[i]){
				if(u.id==v.id)continue;
				dis[u.id][v.id]=min(dis[u.id][v.id],u.t+v.t);
				dis[v.id][u.id]=min(dis[v.id][u.id],u.t+v.t);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		ll ans=1e18;
		scanf("%d%d",&x,&y);
		for(auto u:e[x])
			for(auto v:e[y])ans=min(ans,dis[u.id][v.id]+u.t+v.t);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

