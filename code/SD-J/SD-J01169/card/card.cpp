#include <bits/stdc++.h>
using namespace std;
int n,k;
vector <int> a[300010];
int c[300001],m[300001];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(m,0,sizeof(m));
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&c[i]);
	} 
	for ( int i=1; i<=k; i++ ) 
		printf("0 ",);
	printf("\n");
	return 0;
}
