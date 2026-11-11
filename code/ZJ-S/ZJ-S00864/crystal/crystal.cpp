#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans=0;
	long long l=1,r=1,t=m;
	while(r<n){
		t-=(r-l+1)*(a[r+1]-a[r]);
		r++;
		while(l<r&&t<0){
			t+=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
} 
