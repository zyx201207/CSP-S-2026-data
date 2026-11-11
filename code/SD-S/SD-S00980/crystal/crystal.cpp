#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=1e6+5;
ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))k=k*10+c-'0',c=getchar();
	return f*k;
}
void write(ll x){
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	ll len=0;
	char c[100];
	while(x){c[len++]=x%10+'0';x/=10;}
	while(len--)putchar(c[len]);
}
ll a[N],b[N];
ll ans;
ll find(ll x,ll i,ll l,ll r){
	while(l<r){
		ll mid=(l+r)>>1;
		if(mid*a[i]-b[mid]==x)return mid;
		if(mid*a[i]-b[mid]<x)l=mid+1;
		else r=mid;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		ll ch=i*a[i]-b[i]-m;
		if(ch>0)ans=max(i-find(ch,i,1,i),ans);
		else ans=i;
	}
	write(ans);
	return 0;
}
