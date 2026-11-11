#include <bits/stdc++.h>
using namespace std;
const int maxn=5*1e5;
long long n,m,ans=0;
long long a[maxn],s[maxn];
void nodey(){
	long long dy=a[2]-a[1];
	for(long long i=1;i<=n;i++){
		long long zhi=((i*(i+1)*dy)/2);
		if(zhi>m){
			printf("%lld",i);break;
		}else if(zhi==m){
			printf("%lld",i+1);break;
		}
	}
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
	   scanf("%lld",&a[i]);
	}
	long long d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		long long fa=a[i]-a[i-1];
		if(fa!=d)break;
		else {
			nodey();
			return 0;
		}
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
        long long cnt=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>=m)break;
			cnt=a[j]*(j-i+1)-(s[j]-s[i-1]);
			if(cnt<=m){
		        long long ansx=j-i+1;
				ans=max(ansx,ans);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
