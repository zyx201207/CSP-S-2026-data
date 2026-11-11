#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
bool check(long long len){
	for(int i=1;i+len-1<=n;i++){
		if(len*a[i+len-1]-(sum[i+len-1]-sum[i-1])<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long l=1,r=n,ans=0;
	while(l<r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid;
	}
	cout<<ans;
	return 0;
}
