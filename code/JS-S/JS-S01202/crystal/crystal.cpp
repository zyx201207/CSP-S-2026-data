#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
bool check(long long num){
	for (long long i=num;i<=n;i++){
		if (sum[i]-sum[i-num]-num*(a[n]-a[i])<=m)
		  return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++)
	  sum[i]=sum[i-1]+a[n]-a[i];
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}
		else
		  r=mid-1;
	}
	cout<<ans;
	return 0;
}
