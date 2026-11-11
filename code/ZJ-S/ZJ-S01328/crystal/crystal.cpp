#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=501010;
ll n,m,a[N],sum[N];
ll check(int len){
	ll res=1e18;
	for(int i=1;i+len-1<=n;i++){
		res=min(res,a[i+len-1]*len-sum[i+len-1]+sum[i-1]);
	}return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)<=m){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}cout<<ans;
	return 0;
}
