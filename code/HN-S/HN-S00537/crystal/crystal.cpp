#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],b[500005],c[500005];

bool check(long long x){
	for(long long i=1;i<x;i++){
		long long sum=c[x]-c[i]-i*b[i];
		if(sum<=m){
			ans=max(ans,x-i+1);
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i]*(i-1);
	}             
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
