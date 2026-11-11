#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=1600;
int f[N][N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			if(i==j){
				f[i][i]=0;
				continue;
			}
			f[i][j]=1e9;
		}
	}

	for(int i=1;i<=n;i++){
		int l;
		scanf("%d",&l);
		for(int j=1;j<=l;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			f[a][i+m]=t;
			f[i+m][a]=t;
		}
	}	printf("\n");

	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//				if(i==1&&j==3){
//					printf("YES");
//					printf("%d  %d %d %d\n",f[i][k],f[k][j],k);
//				}
				
			}
		}
	}
//	for(int i=1;i<=n+m;i++){
//		for(int j=1;j<=n+m;j++){
//			if(f[i][j]==1e9){
//				f[i][j]=-1;
//			}
//			printf("f[ %d ][ %d ]:%d   ",i,j,f[i][j]);
//		}
//		printf("\n");
//	}	
	while(p--){
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",f[u][v]+w[u]+w[v]);
	}
	return 0;
} 
