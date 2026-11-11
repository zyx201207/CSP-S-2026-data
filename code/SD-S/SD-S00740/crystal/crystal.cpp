#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
ll n,m,a[500005];
ll sum[500005];
bool check(int x){
	for(int i=x; i<=n; i++){
		ll cnt=x*a[i]-sum[i]+sum[i-x];
		if(cnt<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
