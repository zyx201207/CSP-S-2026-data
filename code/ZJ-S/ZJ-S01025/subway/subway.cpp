#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
long long c,n,m,d,q,w[M],k[N],x,y;
struct node{
	int a,t;
}f[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			scanf("%d %d",&f[i].a,&f[i].t);
		}
	}
	while (q--){
		scanf("%d %d",&x,&y);
		printf("%d",w[x]+f[x].t+f[y].t+w[y]);
	}
	return 0;
}