#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long x[500005];
long long pre[500005];
long long need(long long l,long long r){
	return pre[r]-pre[l-1]-(a[r]-a[l-1])*(l-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){	
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		x[i]=a[i]-a[i-1];
		if(i==1)x[i]=0;
		pre[i]=pre[i-1]+x[i]*(i-1);
	}
	llong long ans=1;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		long long anss;
		while(l<=r){
			long long mid=(l+r)/2;
			if(need(mid,i)>m){
				l=mid+1;
			}else{
				anss=mid;
				r=mid-1;
			}
		}
		ans=max(ans,i-anss+1);
	}
	cout<<ans;
	return 0;
}
