#include<cstdio>
const int maxn=505;
int w[maxn],t[maxn][maxn],a[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%d%d",&t[i][j],&a[i][j]);
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		a[x][y]
	}
	return 0;
}
