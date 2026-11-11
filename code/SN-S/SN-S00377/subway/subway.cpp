//yangzirui xianjiaotongdaxuefushuzhongxue SN-S00377
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[10005][10005];
struct subw{
	int z,tij;
}kij[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=5004;i++){
		for(int j=1;j<=5004;j++){
			a[i][j]=INT_MAX;
		}
	}
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			scanf("%d%d",&kij[j].z,&kij[j].tij);
		}
		for(int j=1;j<=k1;j++){
			for(int k=1;k<=k1;k++){
				if(j!=k) a[kij[j].z][kij[k].z]=min(a[kij[j].z][kij[k].z],kij[j].tij+kij[k].tij);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if((a[i][k]+a[k][j])>0) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",(w[x]+w[y]+a[x][y]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

