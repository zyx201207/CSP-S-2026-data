#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,mn,l,r,ans,a[500005];
bool check(ll x){
	mn=9e18,sum=0;
	for(ll i=1;i<=n;i++){
		if(i>x){
			sum=sum+(a[i]-a[i-1])*(x-1)-(a[i-1]-a[i-x]);
			mn=min(mn,sum);
		}else{
			sum=sum+(a[i]-a[i-1])*(i-1);
			if(i==x)mn=min(mn,sum);
		}
	}
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=0,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
