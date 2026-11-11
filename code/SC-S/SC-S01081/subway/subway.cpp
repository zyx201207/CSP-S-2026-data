#include<bits/stdc++.h>
using std::vector;
using std::min;
typedef long long ll;
const ll inf=1e18;
const int N=500+10,M=5e5+10;
struct T{
	int i,t;
	T(int a,int b):i(a),t(b){}
};
ll dis[N][N];
int w[M];
vector<T> sta[M];
int main(){
	std::freopen("subway.in","r",stdin);
	std::freopen("subway.out","w",stdout);
	int c,n,m,d,q;scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		while(k--){
			int a,t;scanf("%d%d",&a,&t);
			sta[a].emplace_back(i,t);
//			printf("%d %d %d\n",a,i,t);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		int len=sta[i].size();
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++){
				int u=sta[i][j].i,v=sta[i][k].i;
				dis[u][v]=dis[v][u]=min(dis[u][v],(ll)sta[i][j].t+sta[i][k].t);
			}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<i;k++){
			for(int j=1;j<k;j++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;scanf("%d%d",&u,&v);
		ll ans=inf;
		for(int i=0;i<sta[u].size();i++)
			for(int j=0;j<sta[v].size();j++)
				ans=min(ans,sta[u][i].t+dis[sta[u][i].i][sta[v][j].i]+sta[v][j].t);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}