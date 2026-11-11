#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long maxv=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		maxv=max(maxv,i-r+1);
	}
	cout<<maxv;
	return 0;
}