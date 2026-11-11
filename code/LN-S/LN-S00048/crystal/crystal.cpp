#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans;
long long sum[500005],x,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),x+=a[i];
	sort(a+1,a+n+1);
	x/=n;
	if(m==0) printf("1");
	else {
	if(n<=16){
		int g=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int p=m;
				for(int k=i;k<=j;k++){
					p-=a[j]-a[k];
				}
				if(p>=0) g=max(g,j-i+1);
			}
		}
		printf("%d",g);
	}
	else{
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long k=1000000000005;
	for(int i=1;i<=n;i++){
		int t;
		if((sum[i]+m)/i-x>0) t=(sum[i]+m)/i-x;
		else t=x-(sum[i]+m)/i;
		if(t<=k) ans=i,k=t;
	}
	printf("%d",ans);
	}
}
	return 0;
}
