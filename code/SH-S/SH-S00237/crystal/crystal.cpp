#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500010],c[500010],s[500010];
bool check(long long x){
	return s[x]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<n;i++){
		s[i]=c[i]*i+s[i-1];
	}
	sort(s+1,s+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else  r=mid-1;
	}
	cout<<ans;
	return 0;
}
