#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans,lx,rx;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
bool check(ll u){
	ll ad=a[u];
	ll sum=m;
	for(ll k=1;k<=u;k++){
		ll df=ad-a[k];
		sum-=df;
		if(sum<0)
			return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	lx=1;rx=n;
	while(lx<=rx){
		ll mid=(lx+rx)/2;
		if(check(mid)){
			ans=mid;
			lx=mid+1;
		}
		else
			rx=mid-1;
	}
	cout<<ans;
	return 0;
}
