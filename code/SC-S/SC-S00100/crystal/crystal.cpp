#include<bits/stdc++.h>
#define ll long long
#define N 510000
#define gtc getchar
#define ptc putchar
using namespace std;
inline ll read(){
	ll ans=0,w=1;
	char c=gtc();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=gtc();
	}
	while(isdigit(c)){
		ans=ans*10+(c-'0');
		c=gtc();
	}
	return ans*w;
}
inline void write(ll ans){
	if(ans<0) ans=-ans,ptc('-');
	if(ans>9) write(ans/10);
	ptc(ans%10+'0');
}
ll n,m,a[N],cha[N],upre[N],ans=1,sum;
bool check(ll l,ll r){
	ll sum=0;
	for(ll i=r;i>=l;i--){
		sum+=upre[i]-upre[r+1];
		if(sum>m) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(ll i=n-1;i>=1;i--){
			cha[i]=abs(a[i]-a[i+1]);
			upre[i]=cha[i]+upre[i+1];
		}
		for(ll i=3;i<=n;i++){
			ll l=1,r=i-1;
			while(l<r){
				ll mid=l+(r-l)/2;
				if(check(mid,i-1)) r=mid;
				else l=mid+1;
			}
			ans=max(ans,i-l+1);
		}
		write(ans);
		return 0;
	}
	ans=n,sum=(a[1]+a[n])*n/2;
	for(int i=n;i>=1;i--){
		if(sum<=m){write(ans);return 0;}
		ans--,sum-=a[i];
	}
	write(ans);
	return 0;
}