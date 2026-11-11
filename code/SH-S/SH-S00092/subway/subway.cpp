#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k,w[125000],x[100005],y[100005],a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=n;j++){
			scanf("%d%d",&a[i][j],&t[i][j]); 
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",x[i],y[i]);
	}
	return 0;
}
