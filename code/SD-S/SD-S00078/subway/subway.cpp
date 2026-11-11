#include <iostream>

// consider long long
constexpr int N=510,M=100010;
//
//int dfs(int s,int t){
//	for(int i=)
//}

int testcase,n,m,d,q;
int w[M];
int siz[N];
int a[N][M],t[N][M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%d%d%d%d%d",&testcase,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&siz[i]);
		for(int j=1;j<=siz[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%d\n",w[s]+w[t]);
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
