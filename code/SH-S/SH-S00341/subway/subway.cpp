#include <bits/stdc++.h>
using namespace std;

const int N=1010,M=5e5+10;

long long v[M],dis[N][N];
int c,n,m,d,q,k;

struct stu{
	int x;
	long long y;
};
vector<stu> a[M];

void solve_baoli(){
	memset(dis,0x3f,sizeof(dis));
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;++i) dis[i][i]=0;
	
	for(int i=1;i<=m;++i) scanf("%lld",&v[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int x; long long y;
			scanf("%d%lld",&x,&y);
			a[x].push_back(stu{i,y});
		} 
	}
	for(int u=1;u<=m;++u){
		for(int i=0;i<int(a[u].size());++i){
			for(int j=i+1;j<int(a[u].size());++j){
				int p=a[u][i].x,q=a[u][j].x;
				dis[p][q]=dis[q][p]=min(dis[p][q],a[u][i].y+a[u][j].y);
			}
		}
	}
	
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=2e18;
		for(int i=0;i<int(a[x].size());++i)
			for(int j=0;j<int(a[y].size());++j){
				int p=a[x][i].x,q=a[y][j].x;
				ans=min(ans,dis[p][q]+a[x][i].y+a[y][j].y);
			}
		printf("%lld\n",ans+v[x]+v[y]);
	}
}



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve_baoli();
	return 0;
}
