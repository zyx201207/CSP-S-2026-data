#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=2e4+5,maxq=1e5+5;
int c,n,m,d,q,w[maxm],k[maxn],a[maxn][maxm],t[maxn][maxm],x[maxq],y[maxq],i,j;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++){
		scanf("%d",&m);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
		printf("%d\n",w[x[i]]+2*t[1][1]+w[y[i]]);
	}
	return 0;
}
