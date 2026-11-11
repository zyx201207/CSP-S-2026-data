#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++) {
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}
