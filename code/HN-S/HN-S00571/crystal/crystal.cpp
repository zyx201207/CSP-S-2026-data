#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	
	for(long long i=1;i<=n;i++){
		long long l=0,r=n-i,mid;
		while(l<r){
			mid=(l+r)/2;
			long long x=a[i+mid]*(mid+1),y=sum[i+mid]-sum[i-1];
			if(x-y<=m){
				ans=max(ans,mid+1);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
