#include<bits/stdc++.h>
using namespace std;

const long long MAXN=5e5;
long long n,m;
long long a[MAXN+5];
long long qz[MAXN+5];

bool check(long long pos,long long wc){
//	printf("ck:%lld %lld %lld %lld\n",pos,a[pos],pos*a[pos]-qz[pos],m);
	if(a[pos+wc]*(pos)-qz[pos+wc]+qz[wc]<=m){
		return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	qz[1]=a[1];
	for(long long i=2;i<=n;i++){
		qz[i]=a[i]+qz[i-1];
	}
	long long ans=1;
//	printf("%lld\n",a[315275]*315275-qz[315275]);
	for(int py=0;py<=n-ans+1;py++){
		long long l=1,r=n-py;
		long long mid;
		
		while(l<=r){
			mid=(l+r)/2;
//			printf("%lld %lld\n",mid,ans);
			if(check(mid,py)){
				l=mid+1;
				ans=max(ans,mid);
			}else{
				r=mid-1;
			}
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}