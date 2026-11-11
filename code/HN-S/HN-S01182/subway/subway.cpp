#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;

int C,n,m,d,Q;
const int N = 5e2 + 2 ;
const int M = 5e5 + 2 ;
const int D = 22 ;
int mton_u[M][D];
int mton_d[M][D];
int mton[M];
i64 dis[N][N];
int w[M];

int main(){
	//
//	cout<<sizeof(mton_u)/1e6 ;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
		scanf("%d",w+i);
	int x,y,z;
	for(int i=1;i<=n;i++){
		scanf("%d",&z);
		for(int j=0;j<z;j++){
			scanf("%d%d",&x,&y);
			mton[x]++;
			mton_u[x][mton[x]]=i;
			mton_d[x][mton[x]]=y;
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	int u,v;
	i64 s;
	for(int i=1;i<=m;i++){
		for(int j=1;j<mton[i];j++){
		u=mton_u[i][j];
			for(int k=j+1;k<=mton[i];k++){
				v=mton_u[i][k];
				s=(i64)mton_d[i][j]+mton_d[i][k];
				if(s<dis[u][v]){
					dis[u][v]=s;
					dis[v][u]=s;
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(dis[i][j]>dis[i][k]+dis[k][j])
			dis[i][j]=dis[i][k]+dis[k][j];
	}
	i64 ans,t;
//	for(int i=1;i<=n;i++,puts(""))
//	for(int j=1;j<=n;j++){
//		printf("%3lld ",dis[i][j]);
//	}
//	for(int i=1;i<=m;i++){
//		printf("Station %d:\n",i);
//		for(int j=1;j<=mton[i];j++){
//			printf("%d %d\n",mton_u[i][j],mton_d[i][j]);
//		}
//	}
	while(Q--){
		scanf("%d%d",&x,&y);
		ans=0x7fffffffffffffffll;
		for(int i=1;i<=mton[x];i++){
			u=mton_u[x][i];
			for(int j=1;j<=mton[y];j++){
				v=mton_u[y][j];
				t=mton_d[x][i]+mton_d[y][j]+dis[u][v];
				if(t<ans)
					ans=t;
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

