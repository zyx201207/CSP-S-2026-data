#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%d",&n,&d);
		scanf("%d%d",&a[1],&a[2]);
		bool b=1;
		int x=a[1]-a[2];
		for(int i=3;i<=n;i++) {
			scanf("%d",&a[i]);
			if(a[i-1]-a[i]!=x) {
				b=0;
			}
		}
		if(b==1) {
			if(n==2) printf("0\n");
			else printf("%d\n",n-d-1);
			continue;
		}
		for(int i=1;i<=n;i++) {
			if(a[n]-a[i]<=d&&a[i]-a[1]<=d) {
				printf("0\n");
				continue; 
			}
		}
	}
	return 0;
}

