#include<bits/stdc++.h>
using namespace std;
int cccc,T,n,d,a[2000100],c,o,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cccc,&T);
	while(T--){
		scanf("%d%d",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		c=a[n]-a[n-1];
		o=(d/c);
		ans=n+1-2*o;
		if(o==0){
			printf("0\n");
			continue;
		}
//		for(int i=1;i+2*o-1<=n;i++) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
