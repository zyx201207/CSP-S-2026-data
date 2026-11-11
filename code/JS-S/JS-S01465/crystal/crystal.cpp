#include<bits/stdc++.h>
using namespace std;
long long a[600005],b[600005],n,m;
long long erf(long long tar,long long r,long long x)
{
	long long l=0;
	while(l<r){
		long long mid=(l+r)/2;
		long long qian=mid*a[x]-b[mid];
		if(tar-qian<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long ans=-1;
	for(long long i=1;i<=n;i++){
		long long need=a[i]*i-b[i];
		long long uid=erf(need,i,i);
		ans=max(ans,i-uid);
	}
	cout<<ans;
	return 0;
}
