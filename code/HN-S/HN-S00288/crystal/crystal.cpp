#include<bits/stdc++.h>
using namespace std;
long long a[150001],sum[150001];
int erfen(long long n,long long m){
	long long l=0,r=n,mid;
	while(l<r){
		mid=(r+l)>>1;
		if((n+1)*a[n]-sum[n+1]+sum[mid]>m){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,tmp;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;i<n;i++){
		tmp=erfen(i,m);
		if(i-tmp+1>ans) ans=i-tmp+1;
	}
	cout<<ans;
	return 0;
} 
