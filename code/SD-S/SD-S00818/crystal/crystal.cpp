#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],n,m,l,r,ans,f=1,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		k=a[2]-a[1];
		if(a[i]-a[i-1]!=k) f=0;
	}
	if(f==1){
		ans=(sqrt(8*m/k+1)-1)/2+1;
		printf("%lld",&ans);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		b[1]=0;
		l=1;
		r=i;
		while(l<r){
			long long mid=l+(r-l)/2;	
			if(b[i]-b[mid]-(a[i]-a[mid])*(mid-1)<=m) r=mid;
			else l=mid+1; 
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
