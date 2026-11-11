#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,INF=0x7f7f7f7f;
int c,n,m,d,q;
int w[N];
vector<pair<int,int> >mp[M];
int road[N][N];
void floyd(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) road[i][j]=INF;
	for(int i=1;i<=m;i++){
		for(auto j:mp[i]){
			int u=j.first,d1=j.second;
			for(auto k:mp[i]){
				int v=k.first,d2=k.second;
				if(u==v) continue;
				road[v][u]=road[u][v]=min(road[u][v],d1+d2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(road[i][k]!=INF&&road[j][k]!=INF) road[i][j]=min(road[i][j],road[i][k]+road[j][k]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int op;
		scanf("%d",&op);
		for(int j=1;j<=op;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			mp[a].push_back({i,t});
		}
	}
	floyd();
	while(q--){
		int x,y,ans=INF;
		scanf("%d%d",&x,&y);
		for(auto i:mp[x]){
			int u=i.first,d1=i.second;
			for(auto j:mp[y]){
				int v=j.first,d2=j.second;
				ans=min(ans,road[u][v]+d1+d2+w[x]+w[y]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
