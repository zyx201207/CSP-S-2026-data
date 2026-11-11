//十年OI一场空，不开long long见祖宗
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
bool check(ll x){
	ll cnt=0;
	for(int i=1;i<=x;i++)
		cnt+=(a[x]-a[i]);
	if(cnt<=m)return 1;
	for(int i=x+1;i<=n;i++){
		cnt-=(a[i-1]-a[i-x]);
		cnt+=(x-1)*(a[i]-a[i-1]);
		if(cnt<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)/2+1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
/*
今年T1怎么如此之水？？？
不对劲！！！
我的洛谷账号：wudongcheng0223
*/