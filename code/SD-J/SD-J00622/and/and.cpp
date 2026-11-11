#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-0x3f3f3f3f3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		printf("%lld",maxx);
	}
	if(n<=2000){
		for(int i=n;i>=m;i--){ 
			long long ans=a[i]; 
			for(int j=i-1;j>=i-m+1;j--){
				ans&=a[j];
			}
			maxx=max(maxx,ans);
		}
		printf("%lld",maxx);
	}
	else{
		printf("%lld",a[n-m+1]);
	}
	return 0;
} 
