#include<iostream>
using namespace std;
int main(){
	long long n,m,ans=0;
	scanf("%lld%lld",&n,&m);
	long long a[100000];
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=0;i<=n;i++){
		for(long long j=0;j<=n-i;j++){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(long long i=1;i<m;i++){
		if(i==1) ans=a[0]&a[1];
		else ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
}
