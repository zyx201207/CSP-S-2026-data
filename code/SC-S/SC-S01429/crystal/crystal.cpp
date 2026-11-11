#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int mx=5e5+10;
ll n,m,a[mx],s[mx],ans=1;
bool judge(ll x){
	for(ll i=x;i<=n;i++) if((x*a[i]+s[i-x]-s[i])<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(judge(mid)==1) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 