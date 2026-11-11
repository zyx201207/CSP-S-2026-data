#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[20001];
int f[20001];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(f,0,sizeof(f));
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&a[i]);
		//printf("%d",i);
	}
	for ( int i=1; i<=n; i++ ) {
		for ( int j=k; j<=i&&j; j-- ) {
			f[j]=max(f[j-1]&a[i],f[j]);
		}f[1]=max(a[i],f[1]);
		//for ( int j=1; j<=k; j++ ) printf("%d ",f[j]);
		//printf("\n");
	}
	printf("%d\n",f[k]);
	return 0;
}
