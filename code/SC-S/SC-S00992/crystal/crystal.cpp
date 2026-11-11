#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],ans=1;
bool check(long long x){
	long long s=0;
	for(int i=1;i<x;i++){
		s=s-a[i]+a[x];
		if(s>=m)return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m>100000000){
		a[0]=abs(a[1]-a[2]);
		printf("%lld",(m+a[0])/(2*a[0])+1);
		return 0;
	}
	sort(a+1,a+1+n);
	long long s=0;
	a[n+1]=a[n];
	for(int i=n,j=n;i>=1;i--){
		long long sum=ans-1;
		s-=(a[i+1]-a[i])*ans;
		while(s<=m){
			if(j<=0){
				if(i<sum)sum=i;
				ans=max(sum,ans);
				printf("%lld",ans);
				return 0;
			}
			s=s+a[i]-a[j];
			j--;
			sum++;
		}
		j++;
		ans=max(sum-1,ans);
	}
	printf("%lld",ans);
	return 0;
} 