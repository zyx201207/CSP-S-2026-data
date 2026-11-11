#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int a[maxn],b[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		printf("%d",a[i]+b[i]);
	}
	return 0;
}