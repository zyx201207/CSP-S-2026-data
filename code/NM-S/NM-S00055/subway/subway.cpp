#include<bits/stdc++.h>
using namespace std;

int m,n,a[10000000],t[10000000],w[10000000],r,q,x,y,ans,c,d,k;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a[i],&t[i]);
	}
	for(int i=1;i<=r;i++){
		scanf("%d%d",&x,&y);
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",a[i]+t[i]-x+y+w[i]);
	}
	return 0;
}
