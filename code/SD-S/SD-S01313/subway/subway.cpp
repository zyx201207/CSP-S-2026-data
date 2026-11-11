#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
const int _MAXn=510;
const int _MAXm=5e5+100;

int n,m,q,dlim;
vector<pii> edge[_MAXm];
int val[_MAXm];
i64 dis[_MAXn][_MAXn];

int cid;
int k,v1,v2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&cid);
	scanf("%d%d%d%d",&n,&m,&dlim,&q);
	for(int i=1;i<=m;i++)scanf("%d",&val[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&v1,&v2);
			edge[v1].push_back({i,v2});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto ed1:edge[i])for(auto ed2:edge[i]){
			int u=ed1.first,v=ed2.first;
			i64 w1=ed1.second,w2=ed2.second;
			if(u==v)continue;
			if(u>v)swap(u,v);
			dis[u][v]=min(dis[u][v],w1+w2);
			dis[v][u]=min(dis[v][u],w1+w2);
		}
	}
	for(int p=1;p<=n;p++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&v1,&v2);
		i64 ans=0x3f3f3f3f3f3f3f3f;
		for(auto ed1:edge[v1])for(auto ed2:edge[v2]){
			int u=ed1.first,v=ed2.first;
			i64 w1=ed1.second,w2=ed2.second;
			ans=min(ans,dis[u][v]+w1+w2);
		}
		printf("%lld\n",ans+val[v1]+val[v2]);
	}
	return 0;
}

