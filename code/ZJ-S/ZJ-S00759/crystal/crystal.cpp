#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
int check(int mid){
	long long sum=1<<30;
	for(long long i=mid;i<=n;i++){
		sum=min(sum,a[i]*mid-(s[i]-s[i-mid]));
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		//cout<<mid<<" "<<check(mid)<<'\n';
		if(check(mid)<=m){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}