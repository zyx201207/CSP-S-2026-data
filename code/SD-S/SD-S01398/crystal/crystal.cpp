#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],sum[500010],ans[500010],aannss=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	for(ll i=1;i<=n;i++){
		if(sum[i]<=m){ans[i]=i; aannss=max(ans[i],aannss); continue;}
		ll l=1,r=i;
		while(l<=r){
			ll mid=l+r>>1;
			if(sum[i]-sum[mid]-(a[i]-a[mid])*(mid-1)>m) l=mid+1;
			else r=mid-1;
		}
		ans[i]=i-l+1;
		aannss=max(ans[i],aannss);
	}
	cout<<aannss;
	return 0;
}
