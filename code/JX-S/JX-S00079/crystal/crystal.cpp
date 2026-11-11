#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void out(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)out(x/10),putchar((x%10)+'0');
	else putchar(x+'0');
}
ll n,m;
ll a[500005];
bool check(ll x){
	if(x==1)return 1;
	ll sum=0;
	for(int i=1;i<=x-1;i++)sum+=a[i];
	ll id=0,cost=(1ll<<60);
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-sum<=cost){
			cost=a[i]*(x-1)-sum;
			id=i;
		}
		sum-=a[i-x+1];
		sum+=a[i];
	}
	return cost<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	ll l=1,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	out(ans);
	return 0;
}
