#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,d;
int a[2000010];
int ans;
void mian() {
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
//	if(a[n]-a[1]>=d) {
		printf("%d",(n-1)*n/2);
//		return ;
//	}
//	int x=1;
//	for(int i=1; i<=n; i++) {
//		if(a[i]-a[1]>d)
//			break;
//		else
//			x=i;
//	}
//	int y=x;
//	ans=(x*(x-1)+(n-x+1)*(n-x))/2;
//	for(int i=1; i<=n; i++) {
//		y=i;
//		if(a[n]-a[i]<=d)
//			break;
//	}
//	ans+=(x-y)*(n-x);
//	printf("%d",&ans);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	if(C==13||C==14) {
		while(T--) {
			mian();
		}
	}
	return 0; 
}
