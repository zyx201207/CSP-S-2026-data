#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,a[1000005],pl[1000005];
bool check(long long x){
	for(long long i=x;i<=n;i++){
		long long sum=pl[i-1]-pl[i-x];
		if((x-1)*a[i]-sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pl[i]=pl[i-1]+a[i];
	l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
}