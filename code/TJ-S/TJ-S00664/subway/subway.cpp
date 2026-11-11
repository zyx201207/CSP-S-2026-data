#include<cstdio>
#include<algorithm>
int c,n,m,d,q;
int w[500012];
int k[5];
int a[12][500012];
int t[12][500012];
/*int dfs(int now1,int now2,int to){
	
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=2*k[i];j++){
			if(j%2)scanf("%d",&a[i][j]);
			else scanf("%d",&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int sum=w[x]+w[y];
		//....
		printf("%d\n",sum);
	}
	return 0;
}
