#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum=INT_MIN,num=INT_MAX;
long long sum_=0;
long long num_=0;
int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum=max(sum,a[i]);
		num=min(num,a[i]);
	}
	long long l=num,r=sum,mid=(l+r/2);
	while(l<r){
		sum_=0;
		for(int i=1;i<=n;i++){
			if(a[i]<mid){
				sum_=sum_+(mid-a[i]);
			}
		}
		if(sum_>m){
			r=mid-1;
			mid=(l+r)/2;
		}
		else{
//			if(m==sum_) break;
			l=mid+1;
			mid=(l+r)/2;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m<=0) break;
		if(a[i]<mid){
			if(m-(mid-a[i])<0) continue;
			m=m-(mid-a[i]);
			a[i]=mid;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mid){
			num_++;
		}
	}
	printf("%lld",num_);
	return 0;
}
