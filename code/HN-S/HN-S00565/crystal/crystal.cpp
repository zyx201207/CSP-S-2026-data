#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500500],c[500500],sumc[500500],l,r,mid;

bool check(long long x){
	int res=0;
	for(int i=1;i<x;i++){
		res+=a[x]-a[i];
	}
	for(int i=x;i<=n;i++){
		if(res<=m){
			return true;
		}else{
			res-=a[i]-a[i-x+1];
			res+=(x-1)*(a[i+1]-a[i]);
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",r);
	return 0;
} 
