#include<bits/stdc++.h>
using namespace std;
int sum=0;
int c,n,m,d,q,w[500010],a[500010],t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		sum+=w[x]+w[y];
		printf("%d\n",sum);
	}
	return 0;
}
