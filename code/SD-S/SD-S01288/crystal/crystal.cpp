/*
I am about to AFO
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
ll arr[1000010],sum[1000010];
ll m;
inline bool check(ll x,ll pos){
	return (sum[pos]-sum[x-1])>=(arr[pos]*(pos-x+1)-m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read();
	m=read();
	for(ll i=1;i<=n;i++) arr[i]=read();
	sort(arr+1,arr+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
	ll maxx=-1e18;
//	cout<<<<"\n";
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,ans;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,i)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
	return 0;
} 
