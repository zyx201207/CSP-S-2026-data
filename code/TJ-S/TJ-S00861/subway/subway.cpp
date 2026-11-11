#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q;
	scanf("%d%d%d%d%d",&n,&m,&d,&q);
	int a[m+1],t[n+1];
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n+m;i++){
		scanf("%d",&t[i]);
	}
	int mi=1000000,ma=0;
	for(int i=1;i<=n;i++){
		if(a[i]<mi){
			mi=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]>ma){
			ma=a[i];
		}
	}
	printf("%d",(mi+ma)*2);
	return 0;
}
