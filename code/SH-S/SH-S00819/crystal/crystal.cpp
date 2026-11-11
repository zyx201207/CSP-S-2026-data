#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long s=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s=(s*(i-1)+a[i])/i;
	}
	s=(s*n+m)/n;
	long long l=1,r=n;
	sort(a+1,a+n+1);
	while(l<r){
		long long mid=(l+r)/2;
		if(a[mid]>=s){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	if(s-a[r-1]<a[r]-s)r--;
	long long rr=r;
	while(a[rr]==a[r]){
		rr++;
	}
	r=rr;
	long long ans=0;
	for(int i=r;i>=i;i--){
		if(m<0)break;
		ans++;m-=a[r]-a[i];
	}
	cout<<ans;
	return 0;
} 
