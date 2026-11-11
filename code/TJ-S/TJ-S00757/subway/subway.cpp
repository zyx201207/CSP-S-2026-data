#include<cstdio>
#include<algorithm>
#include<vector>
const int INF=0x3f3f3f3f; 
int a[605][5];
int t[605][5];
int k[505];
int w[500010];
int dist[605][605];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q); 
	bool spA=true;
	for (int i=1;i<=m;i++)scanf("%d",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if (k[i]>2)spA=false;
		for (int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	
	if (spA){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				dist[i][j]=INF;
			}
		}
		for (int i=1;i<=n;i++){ 
			if (k[i]==2){dist[a[i][1]][a[i][2]]=std::min(dist[a[i][1]][a[i][2]],t[i][1]+t[i][2]);dist[a[i][2]][a[i][1]]=dist[a[i][1]][a[i][2]];}
		}
		for (int i=1;i<=m;i++)dist[i][i]=0;
		for (int k=1;k<=m;k++){
			for (int i=1;i<=m;i++){
				for (int j=1;j<=m;j++){
					dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
					dist[j][i]=dist[i][j];
				}
			}
		}
		for (int i=1;i<=q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",w[x]+dist[x][y]+w[y]);
		}
	}
	return 0;
} 

