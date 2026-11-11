#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300001],d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		c[a[i]]+=(i-d[a[i]]);
		d[a[i]]+=i;
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	printf("\n");
	return 0;
}