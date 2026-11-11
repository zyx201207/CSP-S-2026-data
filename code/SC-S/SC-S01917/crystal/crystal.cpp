#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500010],sum=0,ans=-1,l,r;
bool fa=1,fb=1;

long long ck(long long x){
	long long p=0,cnt=0;
	for(int i=n;i>=1;i--)
		if(a[i]<=x){
			cnt++;
			p=p+x-a[i];
			if(p>m){
				return cnt-1;
			}
		}
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			fa=0;
		}
		if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2])){
			fb=0;
		}
	}
	if(n==1){
		printf("1");
		return 0;
	}
	if(fa){
		for(long long i=1;;i++)
			if((i*(i+1))/2>m){
				if(i<n){
					printf("%lld",i);
				}else{
					printf("%d",n);
				}
				return 0;
			}
		return 0;
	}
	if(fb){
		for(long long i=1;;i++)
			if((i*(i+1))*(a[2]-a[1])/2>m){
				if(i<n){
					printf("%lld",i);
				}else{
					printf("%d",n);
				}
				return 0;
			}
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=a[1];i<=a[n];i++){
		long long o=ck(i);
		if(o>ans){
			ans=o;
		}
	}
	printf("%lld",ans);
	return 0;
}